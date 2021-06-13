#include <iostream>
#include <future>
#include <vector>
#include <numeric>

template <typename Iter>
int parallel_sum(Iter begin, Iter end){
    typename Iter::difference_type len = end-begin;
    if(len<1000)
        return std::accumulate(begin, end, 0);
    Iter mid = begin+len/2;
    auto handle = std::async(std::launch::async, parallel_sum<Iter>, mid, end);
    int sum = parallel_sum(begin, mid);
    return sum+handle.get();
}

int main() {
    std::vector<int> v(1000, 1);
    std::cout << "Somma: " << parallel_sum(v.begin(), v.end()) << '\n';
    return 0;
}
