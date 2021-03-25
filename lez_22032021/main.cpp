#include <iostream>
class C1 {
    int i;
public:
    C1(): i(0) {
        std::cout << "costruzione dell'oggetto C1() all'indirizzo" << this
 << std::endl;    } //dobbiamo mettere in modo esplicito i costruttore
    int getI() {return i;}
};

class C2 {
    C1 c;
    float f;
public:
    C2(): c(), f(0.0){
        std::cout << "costruzione dell'ggetto C2() all'indirizzo: " << this << std::endl;
    } //dobbiamo mettere in modo esplicito i costruttore
    C1 getC() {return c;}
    float getF() {return f;}
};

int main(){
    C1 c1;
    C2 c2;

    std::cout << "c1.i = " << c1.getI() << std::endl;
    std::cout << "c2.c.i = " << c2.getC().getI() << std::endl;
    std::cout << "c2.c.f = " << c2.getF() << std::endl;
    return 0;
}
