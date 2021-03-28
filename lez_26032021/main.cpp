#include <iostream>

class C{
public:
    C(){
        std::cout << "C() @" << this << std::endl;
    }
    ~C(){
        std::cout << "~C() @" << this << std::endl;
    }

    C(const C& other){
        std::cout << "C(&"<<(void *)&other<<") @" << this << std::endl;
    }

    C& operator=(const C& other){ //operatore di assegnazione
        std::cout << "C @" << this << " = C @" << (void *)&other << std::endl;
        //throw std::exception(); //simuliamo che qui facciamo una operazione che fallisce
        return *this;
    }
};

void f(){
    C c1;
    C c2;

    c2=c1;
    C c13(c1);
    std::cout << "Di qui non passa!"<<std::endl;
}

void g(){
    std::cout << "Entro in g()"<<std::endl;
    f();
    std::cout << "Esco da g()"<<std::endl;
}

int main() {
    try{
        g();
    }catch (std::exception& e){
        std::cout << "Eccezione!"<<std::endl;
    }
    return 0;
}
