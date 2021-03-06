#include <iostream>
#include <string>
#include <cstring>
#include <time.h>
#include "Message.h"
#include "MessageStore.h"

class DurationLogger{
    clock_t time;
    std::string name;
public:
    DurationLogger(const std::string& name){
        std::cout << "sono nel costruttore di DurationLogger() @" << this << std::endl;
        time = clock();
        this->name = name;
    }
    ~DurationLogger(){
        std::cout << "distruggo DurationLogger() @" << this << std::endl;
    }
    std::string getName(){
        return this->name;
    }
    clock_t getTime(){
        return clock()-this->time;
    }
};

int main() {
    /* sblocca
    Message m1(5);
    Message m2(10);

    std::cout << m1 << std::endl << m2 << std::endl;

    Message m3(6);*/

    /*DurationLogger dL("assegnazione_movimento");
    std::cout << ">>>>>>>>>>>>>>>>>>>>starting[" << dL.getName() << "]" << std::endl;
    m3 = std::move(m1); //prova assegnazione per movimento
    std::cout << "<<<<<<<<<<<<<<<<<<<<ending[" << dL.getName() << "]: [" << dL.getTime() << "]"<< std::endl;*/
    /* sblocca
    DurationLogger dL1("assegnazione_copia");
    std::cout << ">>>>>>>>>>>>>>>>>>>>starting[" << dL1.getName() << "]" << std::endl;
    m3 = m2; //prova assegnazione
    std::cout << "<<<<<<<<<<<<<<<<<<<<ending[" << dL1.getName() << "]: [" << dL1.getTime() << "]"<< std::endl;
    std::cout << m3 << std::endl;

    Message m4 = std::move(m2); //prova costruttore di movimento
    std::cout << m4 << std::endl;
    */

   MessageStore ms1(2);
   Message m1(5); //id=0
   Message m2(6); //id=1
   Message m3(7); //id=2

   ms1.add(m1);
   ms1.add(m2);
   ms1.add(m3);
   //la funzione get in MessageStore ritorna std::optional, di seguito una possibile verifica.
   if(auto str = ms1.get(2)){
       std::cout << "ms1(true) returned " << *str << '\n';
   }
   std::cout << "n: " << ms1.getN() << " dim: " << ms1.getSize() << '\n';
   ms1.remove(1);
   ms1.remove(2);
   ms1.compact();
   ms1.printAvailableMessage(ms1); //stampo solo i msg validi (id!=-1)
}
