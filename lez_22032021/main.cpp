#include <iostream>
class C1 {
    int i;
public:
    int getI() {return i;}
};

class C2 {
    C1 c;
    float f;
public:
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
