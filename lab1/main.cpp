#include <iostream>
#include <string>
#include <cstring>
#include "Message.h"

int main() {
    Message m1(5);
    Message m2(10);

    std::cout << m1 << std::endl << m2 << std::endl;

    Message m3{m1};
    std::cout << m3 << std::endl;
    //std::cout << "id: " << m1.getId() << " message: " << m1.getMessage() << std::endl;
    //std::cout << "id: " << m2.getId() << " message: " << m2.getMessage() << std::endl;
}
