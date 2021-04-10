//
// Created by Domenico Cefalo on 06/04/21.
//
#include "MessageStore.h"

MessageStore::MessageStore(int n): n(n), dim(n){
    std::cout << "sono nel costruttore di MessageStore @" << this << std::endl;
    messages = new Message[n];
}
MessageStore::~MessageStore(){
    std::cout << "sono nel distruttore di MessageStore @" << this << std::endl;
    delete[] messages;
}

int MessageStore::find_pos(long id) {
    for(int i = 0; i < dim; ++i) {
        if(messages[i].getId() == id)
            return i;
    }
    return -1;
}

void MessageStore::reallocate(int size){
    Message* new_messages = new Message[size];
    int src=0, dst=0;

    //copio tutti i msg validi nel nuovo vettore
    while (src<dim){
        if(messages[src].getId()>=0){
            new_messages[dst] = messages[src];
            dst++;
        }
        src++;
    }
    delete[] messages;
    dim = size;
    messages = new_messages;
}

//passaggio per riferimento
void MessageStore::add(Message &m) { //inserisce o sovrascrive un nuovo msg se c'è uno con lo stesso id
    std::cout << "sono in add() di MessageStore @" << this << std::endl;
    int pos = find_pos(-1);

    if(pos<0){
        //vuol dire che non c'è spazio ===> occore riallocare il vettore
        reallocate(dim+n);
        pos = find_pos(-1);
    }
    messages[pos] = m;
}

std::optional<Message> MessageStore::get(long id) { //restituisce un messaggio se già presente
    std::cout << "sono in get() di MessageStore @" << this << std::endl;
    for(int i=0; i<n; i++){
        if(messages[i].getId()==id)
            return messages[i];
    }
    return std::nullopt; //oppure return ({})
}

bool MessageStore::remove(long id) { //cancella un messaggio se già presente
    int flag=-1;
    std::cout << "sono in remove() di MessageStore @" << this << std::endl;
    for(int i=0; i<n; i++){
        if(messages[i].getId()==id)
            flag=i;
    }
    if(flag!=-1){
        messages[flag] = Message();
        return true;
    }
    return false;
}
//std::tuple<int, int> MessageStore::stats(); //restituisce il num di msg validi e di elementi vuoti ancora disponibili

void MessageStore::compact() { //compatta l'array (elimina le celle vuote e riporta l'array alla dimensione multiplo di n minimia in grado di contenere tutte le celle)
    int count=0;

    for(int i=0; i<dim; i++){
        if (messages[i].getId()==-1){
            count++;
        }
    }
    if ((count%n)==0){
        reallocate(count);
    } else {
        int new_dim = (count/n+1)*n;
        reallocate(new_dim);
    }
}
