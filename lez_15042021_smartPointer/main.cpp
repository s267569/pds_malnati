#include <iostream>

class A {
    int v;

public:
    A(int v): v(v){} //se ci aggiungo explicit all'inizio giù non funzionerebbe
    int value() {return v;}

};


int main() {
    A a(4); //per invocare il nome del costruttore senza argomenti bisogna usare solo a senza parentesi tonde
                //oppure posso fare A a{} con le parentesi graffe
    std::cout << a.value() << std::endl;
    a=6; //perché non si arrabbia? Perché capisce che la classe A ha un costruttore che accetta un intero e quindi
        //si può trasformare implicitamente dal compilatore in A(6). Se scrivessi sul costruttore di copia
        //EXPLICIT non funzionerebbe
    std::cout << a.value() << std::endl;
    return 0;
}
