#include <iostream>

class Alfa{
public:
    virtual void m1(){
        std::cout << "Alfa::m1()" << std::endl;
    }
};

class Beta{
public:
    virtual void m2(){
        std::cout << "Beta::m2()" << std::endl;
    }
};

class Gamma: public Alfa, public Beta {
    short s;
public:
    void m1(){
        std::cout << "Gamma::m1()" << std::endl;
    }
    void m2(){
        std::cout << "Gamma::m2()" << std::endl;
    }
};


int main(){
    Gamma g;
    Gamma* ptr_g = &g;
    Alfa* ptr1 = static_cast<Alfa*>(ptr_g); //andiamo a vedere nella v-table che ci riguarda
    Beta* ptr2 = &g;
    Gamma* ptr3 = &g;


    //mi aspetto che gli indirizzi siano identici, se invece dichiaro m1 ed m2 virtual qualcosa cambia
    //perché anche se tutti e 3 li ho presi da g qualcosa cambia. Questo perché quello che succede è che io ho
    //bisogno di fare riferimento a tabelle diverse, nel momento in cui riduco il puntatore ad esserlo a Beta
    //allora non vedrà tutta la V-Table che aveva Gamma. GAMMA AVRA' UNA V-TABLE PER OGNI CLASSE CHE ESTENDE
    std::cout << "ptr1: " << ptr1 << std::endl;
    std::cout << "ptr2: " << ptr2 << std::endl;
    std::cout << "ptr3: " << ptr3 << std::endl;

    ptr1->m1();
    ptr2->m2();
}
