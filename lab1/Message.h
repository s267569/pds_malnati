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

    Message(const Message& source);
    Message(Message&& source);
    Message& operator=(const Message& source){ //operatore di assegnazione
        if (this != &source){
            delete[] this->buf;
            this->buf = NULL;
            this->id = source.id;
            this->size = source.size;
            this->buf = new char[size];
            memcpy(this->buf, source.buf, size);
        }
        return *this;
    }
    ~Message(){
        //std::cout << "sono nel distruttore" << std::endl;
        delete[] buf;
    }
};
std::ostream& operator<<(std::ostream& out, const Message& m);
#endif //LAB1_MESSAGE_H
