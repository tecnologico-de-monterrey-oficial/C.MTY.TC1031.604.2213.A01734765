#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

#include "DoublyLinkedList.h"
#include "Log.h"

// Intercambio de dos elementos de la lista
template <class T> void swap(DoublyLinkedList<T> &list, int a, int b) {
  if (a != b) {
    T aux = list[a];
    list[a] = list[b];
    list[b] = aux;
  }
}

void printLogs(vector<Log> logs) {
  for (auto log : logs) {
    cout << log << endl;
  }
}

template <class T> int getPivot(DoublyLinkedList<T> &list, int start, int end) {
  // Opción 2 (Sin listas temporales)
  // Identificamos el pivote (El último elemento de la lista)
  T pivot = list[end];
  // Creamos un indice auxiliar igual a start -1 (auxIndex)
  int auxIndex = start - 1;
  // Recorremos toda la lista desde start hasta end - 1 (index)
  for (int index = start; index <= end - 1; index++) {
    // Validamos si el valor de la lista en index es menor al pivot
    if (list[index] < pivot) {
      // si es menor
      // incrementamos el valor de auxIndex
      auxIndex++;
      // intercambiamos en la lista auxIndex con index
      swap(list, auxIndex, index);
      // else
      // no vamos a hacer nada
    }
  }
  // incrementamos el valor de auxIndex
  auxIndex++;
  // intercambiamos auxIndex con el pivot(end)
  swap(list, auxIndex, end);
  // regresar el valor de auxIndex
  return auxIndex;
}

template <class T>
void quickSort(DoublyLinkedList<T> &list, int start, int end) {
  // Condición de control mientras start < end
  if (start < end) {
    // Encontrar el pivote y hacer las dos listas
    int pivot = getPivot(list, start, end);
    // Ordenamos la lista del lado izquierdo
    quickSort(list, start, pivot - 1);
    // Ordenamos la lista del lado derecho
    quickSort(list, pivot + 1, end);
  }
}

int getPivotF(DoublyLinkedList<Log> &list, int start, int end) {
  // Opción 2 (Sin listas temporales)
  // Identificamos el pivote (El último elemento de la lista)
  string pivot = list[end].newdate;
  // Creamos un indice auxiliar igual a start -1 (auxIndex)
  int auxIndex = start - 1;
  // Recorremos toda la lista desde start hasta end - 1 (index)
  for (int index = start; index <= end - 1; index++) {
    // Validamos si el valor de la lista en index es menor al pivot
    if (list[index].newdate < pivot) {
      // si es menor
      // incrementamos el valor de auxIndex
      auxIndex++;
      // intercambiamos en la lista auxIndex con index
      swap(list, auxIndex, index);
      // else
      // no vamos a hacer nada
    }
  }
  // incrementamos el valor de auxIndex
  auxIndex++;
  // intercambiamos auxIndex con el pivot(end)
  swap(list, auxIndex, end);
  // regresar el valor de auxIndex
  return auxIndex;
}

template <class T>
void quickSortF(DoublyLinkedList<T> &list, int start, int end) {
  // Condición de control mientras start < end
  if (start < end) {
    // Encontrar el pivote y hacer las dos listas
    int pivot = getPivotF(list, start, end);
    // Ordenamos la lista del lado izquierdo
    quickSortF(list, start, pivot - 1);
    // Ordenamos la lista del lado derecho
    quickSortF(list, pivot + 1, end);
  }
}

int binarySearch(DoublyLinkedList<Log> list, string serie) {
  // Definir el límite inferior
  int left = 0;
  // Definir el límite superior
  int right = list.getSize() - 1;
  // Iterar en la lista mientras el límite inferior <= limite superior
  while (left <= right) {
    // Calculo la posición del índice de en medio (limite inferior + limite
    // superior) / 2
    int mid = (left + right) / 2;
    // Reviso si el valor búscado es igual a las primeras tres posiciones del
    // elemento de la posición del índice de en medio
    if (list[mid].serie == serie) //-> comparar con las primeras 3 posiciones
    {
      // Si es igual
      // Reviso si es el primero con ese UBI
      // Primero reviso se ya no hay elementos anteriores
      if (mid == 0) {
        // ya ese el primero por que no hay elementos anteriores
        // regreso el valor de mid
        return mid;
      } else {
        // Comparo con el valor anterior para revisar que sea del mismo ubi
        if (list[mid - 1].serie == serie) {
          // Si es igual, es el que encontré no es el primero
          // Ahora busco en el la lista izquierda
          // actualizo el límite superior con el valor del índice de en medio -
          // 1
          right = mid - 1;
        } else {
          // Ya encontramos el primer elemento del UBI buscado
          // retornamos mid
          return mid;
        }
      }
    } else {
      // Si no es igual
      // Reviso si valor buscado es menor al elemento de la posición del índice
      // de en medio
      if (serie < list[mid].serie) {
        // Si es menor
        // actualizo el límite superior con el valor del índice de en medio - 1
        right = mid - 1;
      } else {
        // Si es mayor
        // actualizo el límite inferior con el valor del índice de en medio + 1
        left = mid + 1;
      }
    }
  }
  // Cuando me salga del ciclo
  // Regreso -1
  return -1;
}

int main() {
  ifstream file;

  // Abrimos el archivo de entrada
  file.open("canalsuez2.txt");

  string date;
  string time;
  string entry;
  string ubi;

  DoublyLinkedList<Log> logs;

  // Recorremos todo el archivo para crear agregar los renglones al vector
  while (file >> date >> time >> entry >> ubi) {

    // Organizamos la fecha en mes y año
    string newdate = "";
    for (int i = 3; i < date.size(); i++) {
      newdate += date[i];
    }

    Log log(date, time, entry, ubi, newdate);
    logs.append(log);
  }

  quickSort(logs, 0, logs.getSize() - 1);

  // printLogs(logs);
  cout << "Qué número de serie desea buscar? (primeros tres caracteres de el "
          "UBI)"
       << endl;
  cin >> ubi;

  int index = binarySearch(logs, ubi);
  cout << "Posición del primer elemento con ese UBI: " << index << endl;
  DoublyLinkedList<Log> elementosEncontrados;

  if (index >= 0) {
    while (logs[index].serie == ubi) {
      elementosEncontrados.append(logs[index]);
      if (index == logs.getSize() - 1) {
        // cambio el valor del ubi para salirme del while
        ubi = "";
      } else {
        index++;
      }
    }
  } else {
    cout << "No hay elementos con ese UBI" << endl;
  }

  quickSortF(elementosEncontrados, 0, elementosEncontrados.getSize() - 1);
  elementosEncontrados.print();

  return 0;
}