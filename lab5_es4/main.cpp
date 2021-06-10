#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <queue>
#include <vector>
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>

#define MAX_LINE 100

int main() {
    auto start = std::chrono::system_clock::now();
    std::queue<std::tuple<std::string, std::string>> messages;
    std::vector<std::string> file_names{"../source0.txt", "../source1.txt", "../source2.txt"};
    std::vector<std::thread> clients;

    std::condition_variable queue_cv;
    std::mutex queue_m;
    int count_dead_clients = 0;

    auto client = [start, &messages, &queue_m, &queue_cv, &count_dead_clients] (std::string& file_name) {
        std::ifstream input{file_name};
        if (!input) {
            std::cerr << "Error in opening file " << file_name << "\n";
            return;
        }
        char line[MAX_LINE+1];
        while (!input.eof()) {
            input.getline(line, MAX_LINE);
            std::string s_line{line};
            std::string::size_type first_space = s_line.find(' ');
            std::string time_s = s_line.substr(0, first_space);
            int time_ms = std::stoi(time_s);
            std::string::size_type second_space = s_line.find(' ', first_space+1);
            std::string source_path = s_line.substr(first_space+1, second_space);
            std::string dest_path = s_line.substr(second_space+1);

            std::chrono::duration<int, std::milli> wake_up{time_ms};
            std::this_thread::sleep_until(start + wake_up);
            std::lock_guard lg{queue_m};
            std::cout << "Pushing from " << file_name << "\n";
            messages.push(std::tuple<std::string, std::string>(source_path, dest_path));
            queue_cv.notify_one();
        }
        std::lock_guard lg{queue_m};
        count_dead_clients++;
        std::cout << "Client of file " << file_name << " ending\n";
    };

    auto server = [&messages, &queue_m, &queue_cv, &count_dead_clients] (const int num_clients) {
        std::unique_lock ul{queue_m};
        ul.unlock();
        while (true) {
            ul.lock();
            queue_cv.wait(ul, [&messages]() { return !messages.empty(); });
            std::tuple<std::string, std::string> request = messages.front();
            messages.pop();
            std::cout << "Popping from server\n";
            ul.unlock();
            std::string source_file = std::get<0>(request);
            std::string dest_file = std::get<1>(request);
            std::cout << "Moving file " << source_file << " into file " << dest_file << std::endl;
            std::rename(source_file.c_str(), dest_file.c_str());
            ul.lock();
            if (count_dead_clients >= num_clients) return;
            ul.unlock();
        }
    };

    for (std::string& file_name:file_names) {
        clients.emplace_back(std::thread(client, std::ref(file_name)));
    }

    std::thread server_thread(server, clients.size());

    for (auto& t:clients) {
        t.join();
    }

    server_thread.join();
    return 0;
}
