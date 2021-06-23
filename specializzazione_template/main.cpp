#include <iostream>
#include <string>

class Person{
    std::string name;
public:
    Person(std::string n): name(n){}
    std::string getName(){ return name;}
};

template <typename T>
class Accum{
private:
    T total;
public:
    Accum(T v): total(v){}
    T operator+=(const T& t){ return total=total+t;}
    T value(){ return total;}
};

template<> class Accum<Person>{
    int total;
public:
    Accum(int start=0): total(start){}
    int operator+=(const Person&){ return ++total;}
    int value(){ return total;}
};

int main() {
    Person p1{"Mario"};
    Person p2{"Rosa"};

    Accum<Person> ap1(0);
    Accum<Person> ap2(1);
    

    int somma;
    somma= ap1.value()+ap2.value();
    std::cout << somma << std::endl;
    return 0;
}