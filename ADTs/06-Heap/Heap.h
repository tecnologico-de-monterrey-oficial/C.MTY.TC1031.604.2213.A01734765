#ifndef Heap_h
#define Heap_h



template <class T>
class Heap
{
private:
    vector<T> heap;
    void swap(int a, int b);
    void downSort(int father);
public:
    Heap();
    Heap(vector<T> list);
    Heap(initializer_list<T> list);
    T getTop();
    void pop();
    void push(T data);
    void print();
    bool isEmpty();
};

template <class T>
void Heap<T>::swap(int a, int b)
{
    T aux = heap[a];
    heap[a] = heap[b];
    heap[b] = aux;
}

template <class T>
void Heap<T>::downSort(int father)
{
    int bigSon;
    while ((father * 2 + 1) < heap.size())
    {
        int son1 = father * 2 + 1;
        if ((father * 2 + 2) < heap.size())
        {
            int son2 = father * 2 + 2;
            (heap[son1] > heap[son2]) ? bigSon = son1 : bigSon = son2;
        }
        else
        {
            bigSon = son1;
        }
        if (heap[father] > heap[bigSon])
        {
            father = heap.size(); 
        }
        else
        {
            swap(father, bigSon);
            father = bigSon;
        }
    }
}

template <class T>
Heap<T>::Heap()
{
}

template <class T>
Heap<T>::Heap(vector<T> list)
{
    heap = list;
    int father = (list.size() - 2) / 2;
    while (father >= 0)
    {
        downSort(father);
        father--;
    }
}

template <class T>
Heap<T>::Heap(initializer_list<T> list)
{
    heap = list;
    int father = (list.size() - 2) / 2;
    while (father >= 0)
    {
        downSort(father);
        father--;
    }

}

template<class T>
T Heap<T>::getTop() {
    if (!isEmpty()) {
        return heap[0];
    } else {
        throw out_of_range("El heap esta vacío");
    }
}

template<class T>
void Heap<T>::pop() {
    swap(0,heap.size()-1);
    heap.pop_back();
    downSort(0);
}

template<class T>
void Heap<T>::push(T data) {
    // Agregamos el elemento al final del heap
    heap.push_back(data);
    // UpSort
    int son = heap.size()-1;
    // bool validate = true;
    // while (son != 0 && validate == true) {
    while (son != 0) {
        int father = (son - 1) / 2;
        if (heap[son] > heap[father]) {
            swap(son, father);
            son = father;
        } else {
            son = 0;
        }
    }

}

template <class T>
void Heap<T>::print()
{
    for (auto el : heap)
    {
        cout << el << " ";
    }
    cout << endl;
}

template<class T>
bool Heap<T>::isEmpty() {
    return heap.size() == 0;
}







#endif