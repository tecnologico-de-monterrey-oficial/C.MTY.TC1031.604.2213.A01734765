#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Log.h"

template <class T>
void swap(vector<T> &list, int a, int b) {
    if (a != b) {
        T aux = list[a];
        list[a] = list[b];
        list[b] = aux;
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

template <class T>
void quickSort(vector<T> &list, int start, int end) {
    if (start < end) {
        int pivot = getPivot(list, start, end);
        quickSort(list, start, pivot - 1);
        quickSort(list, pivot + 1, end);
    }
}

template <class T>
bool binarySearch(vector<T> list, T value) {
    int left = 0;
    int right = list.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (list[mid] == value) {
            return true;
        } else {
            if (value < list[mid]) {
                right = mid -1;
            } else {
                left = mid + 1;
            }
        }
    }
    return false;
}

void printLogs(vector<Log> logs){
    for (auto log: logs){
        cout << log << endl;
        cout << "UBI: " << log.ubi << "datetime" << log.date << " " << log.time << endl;
    }
}








int main(){
string ansFileName;
string ansSerie;
string date;
string time;
string entry;
string ubi;
vector<Log> logs;


    cout << "inserte el nombre del archivo que se leerá" << endl;
    cin >> ansFileName;

    cout << "inserte la serie a buscar (los primeros tres caracteres de el UBI)" << endl;
    cin >> ansSerie;




    ifstream file;
    file.open(ansFileName);



//recorremos todo el archivo para crear agregar los renglones del vector
while (file >> date >> time >> entry >> ubi){
    Log log(date, time, entry, ubi);
    logs.push_back(log);
}

quickSort(logs, 0, logs.size()-1);

ubi = "1TL";
int index = binarySearch(logs,ubi);
cout << "Posición del primer elemento con ese  UBI: " << index << endl; 

printLogs(logs);




return 0;
}
