#include <iostream>

class C{
public:
    C(){
        std::cout << "C() @" << this << std::endl;
    }
    ~C(){
        std::cout << "~C() @" << this << std::endl;
    }
    C& operator=(const C& other){ //operatore di assegnazione
        std::cout << "C @" << this << " = C @" << (void *)&other << std::endl;
        return *this;
    }
};

int main() {
    C c1;
    C c2;
    c2=c1;
    return 0;
}
