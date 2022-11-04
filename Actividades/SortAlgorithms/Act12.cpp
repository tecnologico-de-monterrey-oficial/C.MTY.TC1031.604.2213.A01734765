#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <stdio.h>
#include <sys/time.h>
using namespace std;



//Realiza una aplicación en C++ en forma individual, que contenga un menú de opciones con las siguientes características: 

//Opción para crear listas de datos (vectores) de 2 tipos diferentes de datos (que a tu consideración la manera de crear las listas). 
void createListInt(vector<int> &list, int quantity)
{
  for (int i = 0; i < quantity; i++)
  {
    int num = rand() % 1000 + 1;
    list.push_back(num);
  }
}
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
//Opciones para los dos algoritmos de búsqueda, secuencial y binaria, en donde preguntarás al usuario el dato que desea buscar en las listas creadas en la primera opción.
template <class T>
bool binarySearch(vector<T> list, T n, int &comparisons) {
    comparisons = 0;
    int left = 0;
    int right = list.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        comparisons++;
        if (list[mid] == n) {
            return true;
        } else {
            if (n < list[mid]) {
                right = mid -1;
            } else {
                left = mid + 1;
            }
        }
    }
    return false;
}

template <class T>
bool sequentialSearch(vector<T>list, T n){
for(int i=0 ; i<list.size() ; i++){
    if (list[i] == n){
        return true;
    }
}
    return false;
}
//Opciones para cada uno de los algoritmos de ordenamiento, cuyo objetivo será ordenar la lista creada.

//algoritmos secundarios
template <class T> 
void swap(vector<T> &list, int a, int b){
    int aux = list [a];
    list[a]=list[b];
    list[b]=aux;
}
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

//swap
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
//selection
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
//bubble
template <class T>
void bubbleSort(vector<T> &list, int &comparisons, int &swaps) {
    bool swapped = false;
    for (int step=0; step<list.size()-1; step++) {
        swapped = false;
        for (int index=0; index<list.size()-step-1; index++) {
            comparisons++;
            if (list[index]>list[index+1]) {
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
//insertion
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
//merge
template <class T>
void mergeSort(vector<T> &list, int inf, int sup) {

    if (inf < sup) {
        int mid = (inf + sup) / 2;
        mergeSort(list,inf,mid);
        mergeSort(list,mid+1,sup);
        merge(list, inf, mid, sup);
    }
}
//quick
template <class T>
void quickSort(vector<T> &list, int start, int end) {
    if (start < end) {
        int pivot = getPivot(list, start, end);

        quickSort(list, start, pivot - 1);
        quickSort(list, pivot + 1, end);
    }
}




//Para los algoritmos de ordenamiento, es necesario que muestres en pantalla el resultado de la lista ordenada, así como el tiempo que tomó al algoritmo ejecutarse.
template <class T>
void printList(vector<T> list){
    for (auto el : list) {
        cout << el << " ";
    }
    cout << endl;
}

//Para los algoritmos de ordenamiento básicos, también será necesario que se muestre la cantidad de comparaciones que realizó, así como la cantidad de intercambios. 


//Para los algoritmos de búsqueda, deberás mostrar el tiempo que le tomó al algoritmo buscar el dato proporcionado por el usuario.
void startTime(struct timeval &begin)
{
  gettimeofday(&begin, 0);
}
void getTime(struct timeval begin, struct timeval end)
{
  long seconds, microseconds;
  double elapsed;
  gettimeofday(&end, 0);
  seconds = end.tv_sec - begin.tv_sec;
  microseconds = end.tv_usec - begin.tv_usec;
  elapsed = seconds + microseconds * 1e-6;
  printf("Tiempo de ejecución: %.8f seconds.\n", elapsed);
}



template <class T>
void find(vector<T>list){
int listNumAns;
int typeFindAns;
int comparisons;
T findDataAns;
struct timeval begin, end;

    cout << "¿Que dato deseas buscar en la lista?" << endl;
    cin >> findDataAns;

    cout << "Con que algoritmo deseas buscar el elemento? (1=secuencial, 2=binario)" << endl;
    cin >> typeFindAns;

    if(typeFindAns==1){
    startTime(begin);
        if (sequentialSearch(list, findDataAns)) {
            cout << "seq: Si existe" << endl;
        } else {
            cout << "seq: No existe" << endl;
        }
    getTime(begin, end);  

    } else if(typeFindAns==2){
    startTime(begin);
        if (binarySearch(list, findDataAns, comparisons)) {
            cout << "bi: Si existe" << endl;
        } else {
            cout << "bi: No existe" << endl;
        }
    getTime(begin, end);
    cout << "Comparaciones: " << comparisons << endl;
    }

    return;
}

template <class T>
void sort(vector<T>list){
int sortAns;
int swaps;
int comparisons;
struct timeval begin, end;



    cout << "¿Con que algoritmo deseas organizar la lista? (1=swap, 2=selection, 3=bubble, 4=insertion, 5=merge, 6=quick)" << endl;
    cin >> sortAns;


    if(sortAns==1){
        cout << "Swap Sort" << endl;
        swaps = 0;
        comparisons = 0;
        startTime(begin);
        swapSort(list, comparisons, swaps);
        getTime(begin, end);
        cout << "Comparaciones: " << comparisons << " - intercambios: " << swaps << endl;
        printList(list);

    }else if(sortAns==2){
        cout << "Selection Sort" << endl;
        swaps = 0;
        comparisons = 0;
        startTime(begin);
        selectionSort(list, comparisons, swaps);
        getTime(begin, end);
        cout << "Comparaciones: " << comparisons << " - intercambios: " << swaps << endl;
        printList(list);

    }else if(sortAns==3){
        cout << "Bubble Sort" << endl;
        swaps = 0;
        comparisons = 0;
        startTime(begin);
        bubbleSort(list, comparisons, swaps);
        getTime(begin, end);
        cout << "Comparaciones: " << comparisons << " - intercambios: " << swaps << endl;
        printList(list);

    }else if(sortAns==4){
        cout << "Insertion Sort" << endl;
        swaps = 0;
        comparisons = 0;
        startTime(begin);
        insertionSort(list, comparisons, swaps);
        getTime(begin, end);
        cout << "Comparaciones: " << comparisons << " - intercambios: " << swaps << endl;
        printList(list);

    }else if(sortAns==5){
        cout << "Merge Sort" << endl;
        swaps = 0;
        comparisons = 0;
        startTime(begin);
        mergeSort(list, comparisons, swaps);
        getTime(begin, end);
        cout << "Comparaciones: " << comparisons << " - intercambios: " << swaps << endl;
        printList(list);

    }else if(sortAns==6){
        cout << "Quick Sort" << endl;
        swaps = 0;
        comparisons = 0;
        startTime(begin);
        quickSort(list, comparisons, swaps);
        getTime(begin, end);
        cout << "Comparaciones: " << comparisons << " - intercambios: " << swaps << endl;
        printList(list);

    }


    return;
}





int main(){


vector<int> listInt;
vector<char> listChar;

int listTypeAns;
int listNumAns;

cout << "Bienvenido a la actividad 1.2" << endl;
cout << "¡Empecemos!" << endl;
cout << "¿De que tipo de dato quieres hacer el la lista (1=int, 2=char)" << endl;
cin >> listTypeAns;

if (listTypeAns==1){
    cout << "¿Cuantos elementos quieres en la lista?" << endl;
    cin >> listNumAns;
    createListInt(listInt, listNumAns);
    cout << "Aqui está la lista generada" << endl;
    printList(listInt);

    find(listInt);
    sort(listInt);

} else if (listTypeAns==2){
        cout << "¿Cuantos elementos quieres en la lista?" << endl;
    cin >> listNumAns;
    createListChar(listChar, listNumAns);
    cout << "Aqui está la lista generada" << endl;
    printList(listChar);

    find(listChar);
    sort(listChar);

}



    return 0;
}