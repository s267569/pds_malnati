#include <iostream>
#include <concepts>
#include <vector>

template <typename T>
concept incrementable = requires(T t) {++t;} && std::copyable<T>;

template <incrementable T>
class Counter{
    T val;
public:
    Counter (T start): val(start){}
    T increment() {return  ++val;}
    T value() {return val;}
};



int main() {
    std::vector<int> v;
    Counter<int> c1(0);
    Counter<std::vector<int>::iterator> c2(std::begin(v));
    return 0;
}
