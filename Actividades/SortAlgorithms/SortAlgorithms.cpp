#include <iostream>
#include <vector>
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
void bubbleSort(vector<T> &list, int &comparisons, int &swaps){

}

//imprimir la lista
template <class T>
void printList(vector<T> list){
    for (auto el : list) {
        cout << el << " ";
    }
    cout << endl;
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

// Variables para calcular el tiempo de ejecución
struct timeval begin, end;

vector<int> list;
vector<int> listBase;
int swaps;
int comparisons;

    createListInt(listBase, 100);
    list = listBase;
    swaps=0;
    comparisons=0;
    printList(list);
    startTime(begin);
    swapSort(list, comparisons,swaps);
    getTime(begin, end);
    cout << "comparaciones; " << comparisons << " intercambios: " << swaps << endl;
    printList(list);

    return 0;
}