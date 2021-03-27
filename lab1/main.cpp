#include <iostream>
#include <string>
#include <cstring>
#include "Message.h"

int main() {
    Message m1(1);

    std::cout << "id: " << m1.getId() << std::endl;
    std::cout << "message: " << m1.getMessage() << std::endl;
}
