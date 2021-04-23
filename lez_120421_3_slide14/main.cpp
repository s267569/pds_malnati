#include <iostream>

class Alfa{
public:
    virtual void m1() = 0;
};

class Beta: public Alfa{
public:
    void m1(){
        std::cout << "Beta::m1()" << std::endl;
    }
};

class Gamma: public Alfa{
    void m1(){
        std::cout << "Gamma::m1()" << std::endl;
    }
};

void f(Alfa* ptr){
    ptr->m1();
}

int main(){
    Beta b;
    Gamma g;
    Alfa* ptr1 = &b;
    Alfa* ptr2 = &g;

    //Quando viene generato il codice di f(), da dove viene il puntatore che mi arriva non lo so.
    //Il compilatore agisce funzione per funzione. Tutto quello che può sapere è che gli arriva il puntatore ad Alfa
    //che ha un metodo virtuale m1 che non ha implementazione.
    f(ptr1);
    f(ptr2);
}
