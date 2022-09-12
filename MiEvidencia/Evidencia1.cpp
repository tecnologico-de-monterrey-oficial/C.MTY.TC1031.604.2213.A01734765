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

void printLogs(vector<Log> logs){
    for (auto log: logs){
        cout << log << endl;
    }
}

template <class T>
void quickSort(vector<T> &list, int start, int end) {
    if (start < end) {
        int pivot = getPivot(list, start, end);
        quickSort(list, start, pivot - 1);
        quickSort(list, pivot + 1, end);
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

int main()
{
    ifstream file;

    file.open("canalsuez.txt");

    string date;
    string time;
    string entry;
    string ubi;

    vector<Log> logs;

//recorremos todo el archivo para crear agregar los renglones del vector
while (file >> date >> time >> entry >> ubi){
    Log log(date, time, entry, ubi);
    logs.push_back(log);
}

quickSort(logs, 0, logs.size()-1);

printLogs(logs);




return 0;
}
