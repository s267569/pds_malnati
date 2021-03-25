#include <iostream>
class C1 {
    int i;
public:
    C1(): i(0) {
        std::cout << "costruzione dell'oggetto C1() all'indirizzo" << this
 << std::endl;    } //dobbiamo mettere in modo esplicito i costruttore
    C1(int v): i(v){
        std::cout << "costruzione dell'oggetto C1("<<v<<") all'indirizzo" << this<< std::endl;
    }
    C1(const C1& other): i(other.i){ //sintassi del costruttore di copia
        std::cout << "costruzione di copia all'indirizzo " << this
        << " a partire da un oggetto all'indirizzo " << &other << std::endl;
    }
    int getI() {return i;}
};

void f(C1& c){ //se metto (C1& c) non c'è copia perché passo l'originale e non una copia

}

int main(){
    C1 c1a{32}, c1b{64}; //due istanze indipendenti

    //se io volessi che c1b contenesse gli stessi valori di c1a
    //C1 c1c{c1a}; //sto costruendo il 3° oggetto a partire da quello contenuto in c1a
    f(c1a);




    return 0;
}
