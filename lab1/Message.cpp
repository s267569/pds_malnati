//
// Created by Domenico Cefalo on 27/03/21.
//
#include "Message.h"

int Message::id_counter = 0;

Message::Message(long id, char* buf, int size){
    id = id_counter;
    buf = new char[size];
    this->size = size;
    id_counter++;
}

//costruttore di copia
Message::Message(int size){
    std::cout << "costruzione oggetto all'indirizzo " << this << std::endl;
    id = id_counter;
    buf = new char[size];
    this->size = size;
    buf = mkMessage(size);
    id_counter++;
}

//costruttore di movimento
Message::Message(Message&& source){
    //da implementare...
}
int Message::getId() const{
    return id;
}

int Message::getSize() const{
    return size;
}

char* Message::getMessage() const{
    return buf;
}

char* Message::mkMessage(int n){
    std::string vowels = "aeiou";
    std::string consonants = "bcdfghlmnpqrstvz";
    char* m = new char[n+1];
    for(int i=0; i<n; i++){
        m[i]= i%2 ? vowels[rand()%vowels.size()] :
              consonants[rand()%consonants.size()];
    }
    m[n] = 0 ;
    return m;
}

Message::Message(const Message& source){
    std::cout << "costruzione di copia all'indirizzo " << this
              << " a partire da un oggetto all'indirizzo " << &source << std::endl;
    size = source.size;
    id = source.id;
    buf = new char[source.size];
    memcpy(this->buf, source.buf, size);


}

std::ostream& operator<<(std::ostream& out, const Message& m){
    out << "[id: " << m.getId() << "] ";
    out << "[size: " << m.getSize() << "] ";
    out << "[message: " << m.getMessage() << "] ";
    return out;
}