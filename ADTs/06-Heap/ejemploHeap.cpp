#include <iostream>
#include <vector>
using namespace std;

#include "Heap.h"

template<class T>
void HeapSortD(vector<T>& list) {
    Heap<T> heap(list); 
    list.clear();
    while (!heap.isEmpty()) {
        list.push_back(heap.getTop());
        heap.pop();
    }
}

template<class T>
void HeapSortA(vector<T>& list) {
    MinHeap<T> heap(list); 
    list.clear();
    while (!heap.isEmpty()) {
        list.push_back(heap.getTop());
        heap.pop();
    }
}

int main()
{
    
    vector<int> list = {8,5,17,19,21,28};
    Heap<int> heap(list);

    heap.print();

    return 0;
}
