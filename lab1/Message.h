//
// Created by Domenico Cefalo on 27/03/21.
//

#ifndef LAB1_MESSAGE_H
#define LAB1_MESSAGE_H
#pragma once

#include <iostream>
#include <string>

class Message{
    long id;
    char* buf;
    int size;
private:
    static int id_counter;
public:
    Message(long id, char* buf, int size);
    Message(int size);
    char* mkMessage(int n);
    int getId() const;
    int getSize() const;
    char* getMessage() const;

    ~Message(){
        //std::cout << "sono nel distruttore" << std::endl;
        delete[] buf;
    }
};
std::ostream& operator<<(std::ostream& out, const Message& m);
#endif //LAB1_MESSAGE_H
