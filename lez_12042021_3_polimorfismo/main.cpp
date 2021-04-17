#include <iostream>

class Alfa{
    int v1;
public:
    void m1(){
        std::cout << "Alfa::m1()" << std::endl;
    }
};

class Beta: public Alfa{
    int v2;
public:
    Beta(int i): v2(i){}
public:
    /*void m2(){
        m1();
        std::cout << "Beta::m2()" << std::endl;
    }*/
    void m1(){
        std::cout << "Beta::m1()" << std::endl;
    }
};


int main(){
    //Beta b(5);

    //Alfa* ptr = &b; //questo lo posso scrivere--> lecito perché la classe Beta è un'Alfa poiché eredita in modo
                    //pubblico da Alfa in tutti i posti in cui è lecito mettere un Alfa è lecito mettere Beta.
                    //Dove è lecito mettere un puntatore ad Alfa è lecito mettere un puntatore a Beta.
                    //ptr punta ad Alfa quindi mi fa fare delle cose che si possono fare con Alfa ma non mi fa fare
                    //le cose che si possono fare con Beta. STO RESTRINGENDO IL MIO SCOPE, SE ORIGINARIAMENTE L'OGGETTO
                    //ERA PIU' AMPIO ORA MI LIMITO A VEDERNE SOLO UN PEZZO. E' lecito solo se ho un puntatore.
   //ptr->m1(); questo è lecito
   //ptr->m2(); questa non è lecita

   //Alfa a = b; //mi viene copiato qualcosa ma non tutto l'oggetto B ma solo la parte di cui sto ereditando,
                //i dati specifici invece non saranno proprio copiati. Che ci sia un seguito lui non lo sa.
                //Quando invece lavoro con i puntatori l'oggetto rimane com'è e non sto facendo copie.

   Beta b(5);
   Beta* ptr1 = &b;
   ptr1->m1(); //il compilatore traduce così: Beta__m1(ptr1)

   Alfa* ptr2 = &b;
   ptr2->m1();

   //Però cosa vedo? Quella ereditata o quella ridefinita? Il comportamento di C++ è diverso da Java, qui non si vede
   //Beta::m1() ma in C++ non è così.
}
