#include <iostream>
#include <future>
#include <vector>

std::vector<int> parallel_sort(std::vector<int> v, int start, int end){
    int i;
    int size_vector = v.size();
    std::vector<int> first_vector;
    std::vector<int> second_vector;
    for(i=0; i< end; i++){
        first_vector[i] = v[i];
    }
    std::sort(first_vector.begin(), first_vector.end());

    for (i=start; i<v.size(); i++){
        second_vector[i] = v[i];
    }
    std::sort(second_vector.begin(), second_vector.end());

    auto handle = std::async(std::launch::async, parallel_sort, v, 0, size_vector/2);
    std::vector<int> sum = parallel_sort(v,size_vector/2+1,size_vector);
    return handle.get();
}
int main() {
    std::vector<int> vettore = {2,1,3,4,5,6};
    std::vector<int> res=parallel_sort(vettore, 0, vettore.size());

    return 0;
}
