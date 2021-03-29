#include <iostream>
#include <string>
#include <cstring>
#include "Message.h"

int main() {
    Message m1(5);
    Message m2(10);

    std::cout << m1 << std::endl << m2 << std::endl;

    Message m3(6);
    m3 = std::move(m1); //prova assegnazione per movimento

    //m3 = m2; //prova assegnazione
    std::cout << m3 << std::endl;

    Message m4 = std::move(m2); //prova costruttore di movimento
    std::cout << m4 << std::endl;

}
