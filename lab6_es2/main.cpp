#include <iostream>
#include <future>
#include <vector>

template <typename Iter>
std::vector<int> parallel_sort(std::vector<int> v, Iter start, Iter end){
    Iter mid = v.size()/2;
    int size_vector = v.size();
    std::vector<int> first_vector;
    std::vector<int> second_vector;

    std::sort(first_vector.begin(), first_vector.end());

    auto handle = std::async(std::launch::async, parallel_sort, v, mid, end);
    std::vector<int> sum = parallel_sort(v,start,mid);
    return handle.get();
}
int main() {
    std::vector<int> vettore = {2,1,3,4,5,6};
    std::cout << parallel_sort(vettore, vettore.begin(), vettore.end()) << std::endl;
    return 0;
}
