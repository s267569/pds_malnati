//
// Created by Domenico Cefalo on 27/03/21.
//
#include "Message.h"

int Message::id_counter = 0;

Message::Message(long id, char* buf, int size){
    id = id_counter;
    buf = new char[this->size];
    size = this->size;
    id_counter++;
}

Message::Message(int size){
    std::cout << "sono nel costruttore" <<std::endl;
    id = id_counter;
    buf = new char[this->size];
    size = this->size;
    std::cout << this->size << std::endl;
    id_counter++;
}
int Message::getId(){
    return id;
}

char* Message::getMessage(){
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
