#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Buffer {

    char *buf;
    int size;

public:
    Buffer():size(0),buf(nullptr){};

    Buffer(int size, const char *data):size(size) {
        buf = new char[size];
        copy(data, data+size, buf);
    }

    ~Buffer() {
        delete [] buf;
    }

    void print() {
        cout<<"size: "<<size<<", buff: "<<(void*)buf<<endl;
    }

    Buffer& operator=(const Buffer& source) {
        if(this!=&source) {
            delete [] this->buf;
            this->buf = nullptr;
            this->size = source.size;
            this->buf = new char[size];
            copy(source.buf, source.buf+size, this->buf);
        }
        return  *this;
    }

    Buffer& operator=(Buffer&& source) {
        if(this!=&source) {
            delete [] this->buf;
            this->size = source.size;
            this->buf = source.buf;
            source.buf = nullptr;
        }
        return  *this;
    }
};

int main() {
    char *m1 = "first message";
    char *m2 = "second message";

    Buffer b1(strlen(m1)+1, m1);
    Buffer b2(strlen(m2)+1, m2);
    b1.print();
    b2.print();

    b1 = b2; // come se fosse b1.=(b2)
    std::cout << "costruttore di copia " << std::endl;
    b1.print();

    b1 = move(b2);
    std::cout << "costruttore di movimento " << std::endl;
    b1.print();

    //Buffer bv[10];
}
