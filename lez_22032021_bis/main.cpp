#include <iostream>

class CBuffer{
    size_t size;
    char* ptr;
public:
    CBuffer(size_t size): size(size){
        ptr = new char[size];
        std::cout << "acquisito un blocco di " << size << " bytes all'indirizzo " << (void *)ptr << std::endl;
    }

    ~CBuffer(){
        delete[] ptr;
        std::cout << "rilasciato il all'indirizzo " << (void *)ptr << std::endl;
    }
};

void f(){
    CBuffer b2(64);
}

int main() {
    int i;
    CBuffer b1{32}; //consumo 32 byte allocati da qualche parte in memoria
    std::cout << "enter a number to continue..." << std::endl;
    std::cin >> i;
    f();

    return 0;
}
