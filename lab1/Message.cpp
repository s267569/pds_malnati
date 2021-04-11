//
// Created by Domenico Cefalo on 27/03/21.
//
#include "Message.h"

int Message::id_counter = 0;

Message::Message() {
    std::cout << "sono nel costruttore di default @" << this << std::endl;
    this->id = -1;
    this->size=0;
    this->buf = new char[0]; //attenzione: qui potrei anche mettere uguale a nullptr, però poi devo andare in getMessage a modificare
                            //e fare un if(...==nullptr) return stringa vuota. C'è da capire come far ritornare la str vuota.
}

Message::Message(long id, char* buf, int size){
    this->id = id_counter;
    //this->buf = new char[size+1];
    this->buf = mkMessage(size);
    this->size = size;
    id_counter++;
}

Message::Message(int size){
    id = id_counter;
    //this->buf = new char[size+1];
    this->size = size;
    this->buf = mkMessage(this->size); //già viene allocata la nuova char con la new
    std::cout << "costruzione oggetto all'indirizzo @" << this << " id: " << id_counter << std::endl;
    id_counter++;
}
//costruttore di movimento
Message::Message(Message&& source){
    std::cout << "movimento oggetto dall'indirizzo " << &source << " a @" << this << std::endl;
    this->size = source.size;
    this->id = source.id;
    this->buf = source.buf;
    source.buf = NULL;
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
//costruttore di copia
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