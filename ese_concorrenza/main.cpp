#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <string>

//CountDownLatch -- Java Util Cuncurrent

class CountDownLatch {
    int count;
    std::mutex m;
    std::condition_variable cv;
public:
    CountDownLatch(int initialCount): count(initialCount){}
    void await(){
        //unique_lock perché devo poter chiamare la await della CV che ha bisogno come parametro
        //di un oggetto di tipo unique_lock
        std::unique_lock<std::mutex> ul(m); //prendi possesso del mutex in modalità rilasciabile
        //if (count==0) return;
        while(count >0){
            cv.wait(ul); //devo tener conto delle notifiche spurie
        }

        //possiamo eliminare il while di sopra e potremmo scrivere:
        //cv.wait(ul, [this](){return count == 0;});

    }

    void countDown(){
        std::lock_guard<std::mutex> lg(m);
        if(count>0){
            count--;
            if (count==0)
                cv.notify_all();
        }
    }

    int getCount(){
        std::lock_guard<std::mutex> lg(m);
        return count;
    }
};

int main() {
    CountDownLatch cl(3);

    for (int i=0; i< 5; i++){ //creo un po' di thread
        std::thread t([i, &cl](){
            std::cout << "Thread " << i << " started" << std::endl;
            cl.await(); //mi metto in attesa
            std::cout << "Thread " << i << " finisched" << std::endl;
        });
        t.detach(); //me ne dimentico del thread
    }

    while(true){
        std::string s;
        std::getline(std::cin, s); //aspettare di fare delle cose
        cl.countDown();
        std::cout << "Current count is " << cl.getCount() << std::endl;
        std::cout.flush();
    }
    return 0;
}
