#include <iostream>

class Alfa{
    int v1;
public:
    void m1(){
        std::cout << "Alfa::m1()" << std::endl;
    }
};

class Beta: protected Alfa{
    int v2;
public:
    Beta(int i): v2(i){}
public:
    void m2(){
        m1();
        std::cout << "Beta::m2()" << std::endl;
    }
};

class Gamma: public Beta{
public:
    //costruire un Gamma ora implica costruire un Beta
    Gamma(): Beta(3){}
    void m3(){
        m1();
        m2();
        std::cout << "Gamma::m3()" << std::endl;
    }
};
int main(){
    //Beta b;
    Gamma g;

    g.m3();


    //b.m2();
    //b.m1(); //posso farlo, se estendo Beta con Private o Protected anziché Public questo sarebbe un errore. Metodo m1 non visibile
}