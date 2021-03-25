#include <iostream>

char c;

class CBuffer{
    int size;
    char* ptr;
public:
    CBuffer(int size): size(size){
        ptr = new char[this->size];
    }
};

CBuffer b1(10); //globale
int main() {
    CBuffer b2(20); //locale
    std::cout << "Hello, World!" << std::endl;
    CBuffer* pb3 = new CBuffer(30);
    return 0;
}
