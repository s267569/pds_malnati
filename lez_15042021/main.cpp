#include <iostream>

// costrutto CRTP

template <typename T>
class Base{
    //int v;
    Base(){}
    friend T; //rende la propria parte privata visibile al tipo T
public:
    int value(){ return static_cast<const T&>(*this).value(); }
    //void setValue(int v){this->v=v;}
};

class D: public Base<D> {
public:
    D() {}
    int value(){
        return 2;
    }
};

class C: public Base<C>{
public:
    int value(){
        return 3;
    }
};
int main() {
    /* VERSIONE 1
    D d;
    C c;
    //C e D che hanno accesso al metodo value vedono  ciò che è pubblico dentro Base ma non sono parenti tra di loro

    c.setValue(32);
    std::cout << "c.value(): " << c.value() << std::endl;
    d.setValue(8);
    std::cout << "d.value(): " << d.value() << std::endl;
    c.value();
    d.value();
    */

    D d;
    C c;
    std::cout << "c.value(): " << c.value() << std::endl; //ho un comportamento polimorfico ma entrambe le classi hanno dimensione 1
    std::cout << "d.value(): " << d.value() << std::endl;
    std::cout << sizeof(c)<< std::endl;
    std::cout << sizeof(d) << std::endl;
    return 0;
}
