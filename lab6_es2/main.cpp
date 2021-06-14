#include <iostream>
#include <future>
#include <vector>

std::vector<int> parallel_sort(std::vector<int> v, int start, int end, int level){
    //condizione di terminazione
    if(level==0){
        std::sort(v.begin()+start, v.begin()+end);
        std::vector<int> final(v.begin()+start, v.begin()+end);
        return final;
    }
    int mid = (end-start)/2 + start;
    auto handle = std::async(std::launch::async, parallel_sort, v, mid, end, level-1);
    std::vector<int> result = parallel_sort(v,start,mid, level-1);
    std::vector<int> result_handle = handle.get();
    std::vector<int> final;
    std::merge(result_handle.begin(), result_handle.end(), result.begin(), result.end(), std::back_inserter(final));
    return final;
}
int main() {
    std::vector<int> vettore = {2,1,3,4,5,6};
    std::vector<int> result = parallel_sort(vettore, 0, vettore.size(), 2);

    for(int i:result)
        std::cout << i << std::endl;
    return 0;
}
