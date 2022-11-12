#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "DoublyLinkedList.h"
#include "Log.h"


template <class T>
void quickSort(DoublyLinkedList<T> &list, int start, int end) {
    if (start < end) {
        int pivot = getPivot(list, start, end);

        quickSort(list, start, pivot - 1);
        quickSort(list, pivot + 1, end);
    }
}
template<class T>
int getPivot(DoublyLinkedList<T> &list, int start, int end) {
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
template <class T> 
void swap(DoublyLinkedList<T> &list, int a, int b){
    int aux = list [a];
    list[a]=list[b];
    list[b]=aux;
}
template <class T>
void mergeSort(vector<T> &list, int inf, int sup) {

    if (inf < sup) {
        int mid = (inf + sup) / 2;
        mergeSort(list,inf,mid);
        mergeSort(list,mid+1,sup);
        merge(list, inf, mid, sup);
    }
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



int main(){
string ansFileName;
string ansSerie;

string date;
string time;
string entry;
string ubi;

DoublyLinkedList<Log> logsM;
DoublyLinkedList<Log> logsR;

//Solicite el nombre del archivo de entrada (Ej. canal.txt) y lo abra, 
  cout << "inserte el nombre del archivo que se leerá" << endl;
  cin >> ansFileName;

  ifstream file;
  file.open("canalsuez1.txt");

//almacenando los datos en dos listas doblemente encadenadas (Doubly Linked List), una para los que entran por 
//el Mar Mediterráneo y otra para los buques que entran por el mar Rojo.

  while (file >> date >> time >> entry >> ubi){
    Log log(date, time, entry, ubi);
    if(log.entry=="M"){
      logsM.append(log);
    } else if(log.entry=="R"){
      logsR.append(log);
    }
  }

//logsM.print();
//logsR.print();

//Ordene ambas listas encadenadas por UBI + Fecha + Hora (primero por UBI, al haber empate ordenar por fecha y 
//si persiste el empate por hora). Use los algoritmos Quick Sort o Merge Sort
  //quickSort(logsM, 0, );
  //quickSort(logsR, 0, );






return 0;
}
