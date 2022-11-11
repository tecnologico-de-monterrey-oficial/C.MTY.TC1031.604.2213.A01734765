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

int binarySearch(vector<Log> list, string serie){
    int left = 0;
    int right = list.size() - 1;
    while (left <= right){
        int mid = (left + right) / 2;
        if (list[mid].serie == serie) {
            if (mid == 0) {
                return mid;
            } else {
                if (list[mid-1].serie == serie) {
                    right = mid - 1;
                } else {
                    return mid;
                }
            }
        }else{
            if (serie < list[mid].serie) {
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
    }
    return -1;
}

void printLogs(vector<Log> logs){
    for (auto log: logs){
        cout << log << endl;
        //cout << "UBI: " << log.ubi << " " << "datetime" << " " << log.date << " " << log.time << endl;
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

//Solicite el nombre del archivo de entrada (Ej. canal.txt) y lo abra, almacenando los datos en un vector.
    cout << "inserte el nombre del archivo que se leerá" << endl;
    cin >> ansFileName;

    ifstream file;
    file.open(ansFileName);

    while (file >> date >> time >> entry >> ubi){
        Log log(date, time, entry, ubi);
        logs.push_back(log);
    }


//Ordene la información por UBI + Fecha (primero por UBI, al haber empate ordenar por fecha).
//Utiliza Merge Sort o Quick Sort para ordenar los datos.
    quickSort(logs, 0, logs.size()-1);

//Solicite al usuario la serie a buscar (los primeros tres caracteres de el UBI).
    cout << "inserte la serie a buscar (los primeros tres caracteres de el UBI)" << endl;
    cin >> ansSerie;

//Despliegue todas las entradas al canal de los buques de esas series en forma ordenada UBI+Fecha.
//Utiliza Merge Sort o Quick Sort para ordenar los datos.
    ubi = ansSerie;
    int index = binarySearch(logs,ubi);
    cout << "Posición del primer elemento con ese UBI: " << index << endl;

    if (index >= 0) {
        while (logs[index].serie == ubi) {
            cout << logs[index] << endl;
            if (index == logs.size()-1) {
                ubi = "";
            } else {
                index++;
            }
        }
    } else {
        cout << "No hay elementos con ese UBI" << endl;
    }

return 0;
}
