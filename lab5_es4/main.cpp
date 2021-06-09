#include <iostream>
#include <fstream>
#include <chrono>
#include <queue>
#include <tuple>
#include <mutex>
#include <condition_variable>
#include <thread>
#define MAX_THREADS 10
#define MAX_LINE 100


int main() {
    auto start = std::chrono::system_clock::now();
    std::queue<std::tuple<std::string, std::string>> messagges;
    std::vector<std::string> file_names; //contengono i nomi dei file

    auto client = [start,&messagges](std::string& file_name){
        std::chrono::time_point previous = start;
        std::ifstream input{file_name};
        if(!input){
            std::cout << "Error in opening file" << std::endl;
            return;
        }
        while(!input.eof()){
            char line[MAX_LINE+1];
            input.getline(line, MAX_LINE);
            std::string s_line{line};
            std::string::size_type first_space = s_line.find(" ");
            std::string time_s = s_line.substr(0,first_space);
            int time_ms = std::stoi(time_s);
            std::string::size_type second_space = s_line.find(" ", first_space+1);
            std::string source_path = s_line.substr(first_space+1, second_space);
            std::string dest_path = s_line.substr(second_space+1);


            messagges.push(std::tuple<std::string, std::string>(source_path, dest_path));


        }


    };
    return 0;
}
