#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <stdio.h>
#include <sys/time.h>
using namespace std;



// Obtiene el tiempo inicial para calcular el tiempo transcurrido por un algoritmo
void startTime(struct timeval &begin)
{
  // start time
  gettimeofday(&begin, 0);
}

// Imprime el tiempo transcurrido desde el valor de start hasta el momento que se ejecuta la función
void getTime(struct timeval begin, struct timeval end)
{
  long seconds, microseconds;
  double elapsed;
  // end time
  gettimeofday(&end, 0);
  seconds = end.tv_sec - begin.tv_sec;
  microseconds = end.tv_usec - begin.tv_usec;
  elapsed = seconds + microseconds * 1e-6;
  printf("Tiempo de ejecución: %.8f seconds.\n", elapsed);
}

//busqueda secuencial (O(n))
template <class T>
bool sequentialSearch(vector<T>list, T n){
    for(int i=0 ; i<list.size() ; i++){
        if (list[i] == n){
            return true;
        }
    }
//otra opción
/*for(auto el : list){
    if(el == n){
        return true;
    }
}*/
    return false;
}

//busqueda binaria (O(log2 n))
template <class T>
bool binarySearch(vector<T>list, T value){
    int infLim = 0;
    int supLim = (list.size()-1);

    while (infLim <= supLim){
        int midPos = (infLim + supLim)/2;

        if(list[midPos] == value){
            return true; 
        }else{ 
            if(list[midPos] < value){
            infLim = midPos + 1;
            }else{
            supLim = midPos - 1;
            }
        }
    }
    return false;
}

//intercambio de dos elementos de la lista
template <class T> 
void swap(vector<T> &list, int a, int b){
    int aux = list [a];
    list[a]=list[b];
    list[b]=aux;
}

//ordenamiento de intercambio
template <class T>
void swapSort(vector<T> &list, int &comparisons, int &swaps){
    for (int step=0 ; step<list.size()-1 ; step++){
        for(int index=step+1 ; index<list.size() ; index++){
            comparisons++;
            if(list[step] > list[index]){
                swaps++;
                swap(list,step,index);
            }
        }
    }
}

//ordenamiento de burbuja
template <class T>
void bubbleSort(vector<T> &list, int &comparisons, int &swaps) {
    bool swapped = false;
    for (int step=0; step<list.size()-1; step++) {
        swapped = false;
        for (int index=0; index<list.size()-step-1; index++) {
            comparisons++;
            if (list[index]>list[index+1]) {o
                swap(list, index, index+1);
                swaps++;
                swapped = true;
            }
        }
        if (!swapped) {
            return;
        }
    }
}

//ordenamiento de seleción
template <class T>
void selectionSort(vector<T> &list, int &comparisons, int &swaps) {
    for (int step=0; step<list.size()-1; step++) {
        int minor = step;
        for (int index=step+1; index<list.size(); index++) {
            comparisons++;
            if (list[index]<list[minor]) {
                minor = index; 
            }
        }
        if (minor != step) {
            swap(list, minor, step);
            swaps++;
        }
    }
}

//ordenamiento de inserción
template <class T>
void insertionSort(vector<T> &list, int &comparisons, int &swaps) {
    for (int step=1; step<list.size(); step++) {
        int index = step;
        comparisons++;
        while (index > 0 && list[index] < list[index-1]) {
            swap(list, index, index-1);
            swaps++;
            index--; 
            comparisons++;
        }
    }
}

//imprimir la lista
template <class T>
void printList(vector<T> list){
    for (auto el : list) {
        cout << el << " ";
    }
    cout << endl;
}

//fusiona
template<class T>
void merge(vector<T> &list, int inf, int mid, int sup) {
    vector<T> left;
    for (int i=inf; i<=mid; i++) {
        left.push_back(list[i]);
    }
    vector<T> right;
    for (int i=mid+1; i<=sup; i++) {
        right.push_back(list[i]);
    }
    int idxLeft = 0;
    int idxRight = 0;
    int idx = inf;
    while (idxLeft < left.size() && idxRight < right.size()) {
        if (left[idxLeft] < right[idxRight]) {
            list[idx] = left[idxLeft];
            idx++;

            idxLeft++;
        } else {
            list[idx] = right[idxRight];
            idx++;
            idxRight++;
        }
    }
    while (idxLeft < left.size()) {
        list[idx] = left[idxLeft];
        idx++;
        idxLeft++;
    }
    while (idxRight < right.size()) {
        list[idx] = right[idxRight];
        idx++;
        idxRight++;
    }
}

//ordenamiento de fusión
template <class T>
void mergeSort(vector<T> &list, int inf, int sup) {

    if (inf < sup) {
        int mid = (inf + sup) / 2;
        mergeSort(list,inf,mid);
        mergeSort(list,mid+1,sup);
        merge(list, inf, mid, sup);
    }
}

//Conseguir el pivote para el ordenamiento rápido
template<class T>
int getPivot(vector<T> &list, int start, int end) {
    T pivot = list[end];
    int auxIndex = start - 1;
    for (int index=start; index<=end-1; index++) {
        if (list[index]<pivot) {
            auxIndex++;
            swap(list, auxIndex, index);
        }
    }
    auxIndex++;
    swap(list, auxIndex, end);
    return auxIndex;
}

//Ordenamiento rápido
template <class T>
void quickSort(vector<T> &list, int start, int end) {
    if (start < end) {
        int pivot = getPivot(list, start, end);

        quickSort(list, start, pivot - 1);
        quickSort(list, pivot + 1, end);
    }
}

//Conseguir el pivote para el ordenamiento rápido 2
template<class T>
int getPivot2(vector<T> &list, int start, int end) {
    T pivot = list[end];
    vector<T> left;
    vector<T> right;
    for (int index=start; index<=end-1; index++) {
        if (list[index] < pivot) {
            left.push_back(list[index]);
        } else {
            right.push_back(list[index]);
        }
    }

    int index = start;
    for (int i=0; i<left.size(); i++) {
        list[index] = left[i];
        index++;
    }
    int pivotIndex = index;
        list[pivotIndex] = pivot;
    index++;
    for (int i=0; i<right.size(); i++) {
        list[index] = right[i];
        index++;
    }
    return pivotIndex;
}

//Ordenamiento rápido 2
template <class T>
void quickSort2(vector<T> &list, int start, int end) {
    if (start < end) {
        int pivot = getPivot2(list, start, end);
        quickSort2(list, start, pivot - 1);
        quickSort2(list, pivot + 1, end);
    }
}

// Crea una lista aleatoria de enteros
void createListInt(vector<int> &list, int quantity)
{
  for (int i = 0; i < quantity; i++)
  {
    int num = rand() % 1000 + 1;
    list.push_back(num);
  }
}

// Crea una lista aleatoria de caracteres
void createListChar(vector<char> &list, int quantity)
{
  for (int i = 0; i < quantity; i++)
  {
    int num = 91;
    while (num >= 91 && num <= 96)
    {
      num = rand() % 58 + 65;
    }
    list.push_back(char(num));
  }
}




int main(){

srand(time(0));

    // Variables para calcular el tiempo de ejecución
    struct timeval begin, end;
    chrono::high_resolution_clock::time_point begin;
    chrono::high_resolution_clock::time_point end;
    
    vector<char> list;
    vector<char> listBase;
    int swaps;
    int comparisons;

    createListChar(listBase, 20000);
    
    // Swap Sort
    cout << "Swap Sort" << endl;
    list = listBase;
    swaps = 0;
    comparisons = 0;
    // printList(list,0);
    startTime(begin);
    swapSort(list, comparisons, swaps);
    getTime(begin, end);
    cout << "Comparaciones: " << comparisons << " - intercambios: " << swaps << endl;
    // printList(list,1);

    // Bubble Sort
    cout << "Bubble Sort" << endl;
    list = listBase;
    swaps = 0;
    comparisons = 0;
    // printList(list,0);
    startTime(begin);
    bubbleSort(list, comparisons, swaps);
    getTime(begin, end);
    cout << "Comparaciones: " << comparisons << " - intercambios: " << swaps << endl;
    // printList(list,1);
    
    // Selection Sort
    cout << "Selection Sort" << endl;
    list = listBase;
    swaps = 0;
    comparisons = 0;
    // printList(list,0);
    startTime(begin);
    selectionSort(list, comparisons, swaps);
    getTime(begin, end);
    cout << "Comparaciones: " << comparisons << " - intercambios: " << swaps << endl;
    // printList(list,1);
    
    // Insertion Sort
    cout << "Insertion Sort" << endl;
    list = listBase;
    swaps = 0;
    comparisons = 0;
    // printList(list,0);
    startTime(begin);
    insertionSort(list, comparisons, swaps);
    getTime(begin, end);
    cout << "Comparaciones: " << comparisons << " - intercambios: " << swaps << endl;
    // printList(list,1);
    
    // Merge Sort
    cout << "Merge Sort" << endl;
    list = listBase;
    swaps = 0;
    comparisons = 0;
    // printList(list,0);
    startTime(begin);
    mergeSort(list, 0, list.size()-1);
    getTime(begin, end);
    // printList(list,1);

    // Quick Sort
    cout << "Quick Sort" << endl;
    list = listBase;
    swaps = 0;
    comparisons = 0;
    // printList(list,0);
    startTime(begin);
    quickSort(list, 0, list.size()-1);
    getTime(begin, end);
    // printList(list,1);

    // Quick Sort2
    cout << "Quick Sort" << endl;
    list = listBase;
    swaps = 0;
    comparisons = 0;
    // printList(list,0);
    startTime(begin);
    quickSort2(list, 0, list.size()-1);
    getTime(begin, end);
    // printList(list,1);




    return 0;
}