#include <iostream>
#include <functional>
#include <math.h>
std::function<float(float, float)> f; //var che può essere inizializzata a partire da una funz. sempl

int main() {
    //f può essere quindi popolata a partire da una funzione semplice
    //f = fmaxf;

    //Possiamo farlo con una funzione lambda
    //f = [](float x, float y) -> float {return x > y ? x : y; };

    //Un altro metodo ancora con oggetto functional:
    class functional{
    public:
        float operator() (float x, float y){
            return (x>y ? x:y);
        }
    };
    f = functional{};

    float a = 13.5;
    float b = 4.43;

    std::cout << "il massimo tra " << a << " e " << b << " e' " << f(a,b) << std::endl;

    return 0;
}
