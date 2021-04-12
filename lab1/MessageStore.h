//
// Created by Domenico Cefalo on 06/04/21.
//

#ifndef LAB1_MESSAGESTORE_H
#define LAB1_MESSAGESTORE_H
#include "Message.h"
#include <optional>

class MessageStore{
    Message* messages;
    int dim; //dimensione corrente array
    int n;   //incremento memoria

    int find_pos(long id);
    void reallocate(int size);
public:
    MessageStore(int n);
    ~MessageStore();
    void add(Message &m);                   //inserisce o sovrascrive un nuovo msg se c'è uno con lo stesso id
    std::optional<Message> get(long id);   //restituisce un messaggio se già presente
    bool remove(long id);                 //cancella un messaggio se già presente
    std::tuple<int, int> stats();        //restituisce il num di msg validi e di elementi vuoti ancora disponibili
    void compact();                     //compatta l'array (elimina le celle vuote e riporta l'array alla dimensione multiplo di n minimia in grado di contenere tutte le celle)
    void printAll();
    int getN();
    int getSize();
    void printAvailableMessage(MessageStore &ms);
};

#endif //LAB1_MESSAGESTORE_H
