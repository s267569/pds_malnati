#include <iostream>
#include <future>
#include <string>

double f1(double p2, double p3){
    double f1 = p2+1+p3;
    return f1;
}

int f2(int p2){
    int f2=p2+10;
    return f2;
}

int main() {
    //calcola f1 + f2
    std::future<double> future1 = std::async(f1,3.14, 1);
    double res2 = f2(18);
    future1.wait();
    double res1 = future1.get();
    double result = res1+res2;

    std::cout << "Risultato: " << result << std::endl;
    return 0;
}
