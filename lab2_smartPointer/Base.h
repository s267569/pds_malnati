//
// Created by Domenico Cefalo on 16/05/21.
//

#ifndef LAB2_SMARTPOINTER_BASE_H
#define LAB2_SMARTPOINTER_BASE_H
#include <string>
#include <iostream>

class Base{
    std::string name;
    int type;
    Base() = delete; //rendiamo il costruttore come privato e non può essere INSTANZIATO
    Base(const Base& base) = delete;
    Base(Base&& base) = delete;
protected:
    static int level;
    Base(std::string name):name(name){};
public:
    std::string getName() const{
        return name;
    }
    virtual int mType() const = 0; //questo metodo in classe Base non ha implementazione
    virtual void ls(int indent) const= 0;
    virtual ~Base(){}

};
#endif //LAB2_SMARTPOINTER_BASE_H
