#include <iostream>

// costrutto CRTP

class Base{
    Base(){}

public:
    int value(){ return 32; }
};

class D: public Base {

};
int main() {
    D d;
    return 0;
}
