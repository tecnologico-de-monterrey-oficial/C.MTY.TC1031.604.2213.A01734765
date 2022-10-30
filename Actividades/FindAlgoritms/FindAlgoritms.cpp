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


int main(){

// Variables para calcular el tiempo de ejecución
struct timeval begin, end;

vector<int> list = {5,7,10,20,35,42,63,70,93,100,120,130,140,150,155,167,168,169,200};
int n=0;

while (n<1 || n>200) {
        cout << "Teclea un número entero entre 1 y 200" << endl;
        cin >> n;
        if (n<1 || n>200) {
            cout << "Error: El número debe de estar entre 1 y 200" << endl;
        }
}

startTime(begin);
if (sequentialSearch(list, n)) {
        cout << "seq: Si existe" << endl;
    } else {
        cout << "seq: No existe" << endl;
    }
getTime(begin,end);


startTime(begin);
if (binarySearch(list, n)) {
        cout << "bi: Si existe" << endl;
    } else {
        cout << "bi: No existe" << endl;
    }
getTime(begin,end);


    return 0;
}


