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
    Message();
    Message(long id, char* buf, int size);
    Message(int size);
    char* mkMessage(int n);
    int getId() const;
    int getSize() const;
    char* getMessage() const;

    Message(const Message& source); //costruttore di copia
    Message(Message&& source); //costruttore di movimento
    Message& operator=(const Message& source){ //operatore di assegnazione
        if (this != &source){
            std::cout << "op. di assegnazione Message @" << this << " = Message @" << (void *)&source << std::endl;
            delete[] this->buf;
            this->buf = NULL;
            this->id = source.id;
            this->size = source.size;
            this->buf = new char[size];
            memcpy(this->buf, source.buf, size);
        }
        return *this;
    }
    Message& operator=(Message &&source){ //operatore di assegnazione per movimento
        if (this != &source){
            std::cout << "op. di assegnazione per movimento Message @" << this << " = Message @" << (void *)&source << std::endl;
            delete[] this->buf;
            this->size = source.size;
            this->id = source.id;
            this->buf = source.buf;
            source.buf=NULL;
        }
        return *this;
    }
    ~Message(){
        std::cout << "distruggo Message @" << this << std::endl;
        delete[] buf;
    }
};
std::ostream& operator<<(std::ostream& out, const Message& m);
#endif //LAB1_MESSAGE_H
