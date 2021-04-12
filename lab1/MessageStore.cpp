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
    std::cout << "sto facendo la realloc per " << size << " celle" << std::endl;
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
    std::cout << "sono in add() di MessageStore @" << this << " id: " << m.getId() << std::endl;
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
    for(int i=0; i<dim; i++){
        if(messages[i].getId()==id)
            return messages[i];
    }
    return std::nullopt; //oppure return ({})
}

bool MessageStore::remove(long id) { //cancella un messaggio se già presente
    int flag=-1;
    std::cout << "sono in remove() di MessageStore @" << this << " id: " << id << std::endl;
    for(int i=0; i<dim; i++){
        if(messages[i].getId()==id)
            flag=i;
    }
    if(flag!=-1){
        std::cout << "flag: " << flag << std::endl;
        messages[flag] = Message(); //viene sostituito con un msg vuoto
        return true;
    }
    return false;
}
//std::tuple<int, int> MessageStore::stats(); //restituisce il num di msg validi e di elementi vuoti ancora disponibili

void MessageStore::compact() { //compatta l'array (elimina le celle vuote e riporta l'array alla dimensione multiplo di n minimia in grado di contenere tutte le celle)
    int count=0;
    int new_dim;

    for(int i=0; i<dim; i++){
        count += messages[i].getId()>=0?1:0;
    }
    new_dim = count%n;
    if (new_dim==0)
        new_dim = count;
    else
        new_dim = (1+count/n)*n;

    std::cout << "sono nella funzione compact() e passo da: " << dim << " a: " << new_dim << std::endl;
    reallocate(new_dim);
}

void MessageStore::printAll(){
    for(int i=0; i<dim; i++){
        if(messages[i].getId()!=-1)
            std::cout << messages[i].getMessage() << std::endl;
    }
}

int MessageStore::getN(){
    return this->n;
}
int MessageStore::getSize(){
    return this->dim;
}

void MessageStore::printAvailableMessage(MessageStore &ms){
    for(int i=0; i<ms.getSize(); i++)
        if(ms.messages[i].getId()!=-1){
            std::cout << "id: " << ms.messages[i].getId() << " text: " << ms.messages[i].getMessage() << std::endl;
        }
}
