#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

#include "Log.h"
#include "Heap.h"
#include "MinHeap.h"
//#include "BST.h"


template<class T>
void HeapSortD(vector<T>& list) {
    // Creamos un heap en base a la lista
    Heap<T> heap(list); 
    // removemos todos los elementos de la lista
    list.clear();
    // Eliminamos todos los elementos del heap hasta que este vacío
    while (!heap.isEmpty()) {
        // Insertamos en la lista el primer elemento del heap
        list.push_back(heap.getTop());
        // Removemos el primer elemento del heap
        heap.pop();
    }
}

template<class T>
void HeapSortA(vector<T>& list) {
    // Creamos un heap en base a la lista
    MinHeap<T> heap(list); 
    // removemos todos los elementos de la lista
    list.clear();
    // Eliminamos todos los elementos del heap hasta que este vacío
    while (!heap.isEmpty()) {
        // Insertamos en la lista el primer elemento del heap
        list.push_back(heap.getTop());
        // Removemos el primer elemento del heap
        heap.pop();
    }
}

void printLogs(vector<Log> logs){
    for (auto log: logs){
        cout << log << endl;
        cout << "UBI: " << log.ubi << " " << "datetime" << " " << log.date << " " << log.time << endl;
    }
}




int main(){

string ansFileName;
string ansSerie;

string date;
string time;
string entry;
string ubi;

vector<Log> logsM;
vector<Log> logsR;
//BST<Log> bst;


//Solicite el nombre del archivo de entrada (Ej. canal.txt) y lo abra,
    cout << "inserte el nombre del archivo que se leerá" << endl;
    cin >> ansFileName;

    ifstream file;
    file.open(ansFileName);

 
//almacenando los datos en dos listas (use la clase vector para crear las listas) una para los que entran 
//por el Mar Mediterráneo y otra para los buques que entran por el mar Rojo.


    while (file >> date >> time >> entry >> ubi){
        Log log(date, time, entry, ubi);
        //bst.insert(log);
        
        if(entry=="M"){
            logsM.push_back(log);
        } else if(entry=="R")
            logsR.push_back(log);

    }


//Ordene ambas listas de mayor a menor y de menor a mayor por UBI + Fecha + Hora (primero por UBI, al haber empate 
//ordenar por fecha y si persiste el empate por hora). Use el algoritmo de HeapSort para ordenar las listas.
    //Despliegue la lista ordenada de acuerdo a la solicitud del usuario.
    
    int listAns;//respuesta de la pregunta de que lista
    int sortAns;//respuesta de m->M o M->m
    
    cout << "¿Cual lista quieres ordenar?: " << endl;
    cout << "Buques del Mar Mediterraneo = 1 " << endl;
    cout << "Buques del Mar Rojo = 2 " << endl;
    cin >> listAns;

//Mar Mediterraneo
    if (listAns==1){
        cout << "¿Como lo quieres ordenar?: " << endl;
        cout << "de mayor a menor = 1" << endl;
        cout << "de menor a mayor = 2 " << endl;
        cin >> sortAns;

        //de mayor a menor
        if (sortAns==1){

            HeapSortD(logsM);
            for (auto el : logsM) {
            cout << el << endl;
            }

        //de menor a mayor
        } else if (sortAns==2){
            
            HeapSortA(logsM);
            for (auto el : logsM) {
            cout << el << endl;
            }          
        }
        
        
//Mar Rojo   
    } else if (listAns==2){
        cout << "¿Como lo quieres ordenar?: " << endl;
        cout << "de mayor a menor = 1" << endl;
        cout << "de menor a mayor = 2 " << endl;
        cin >> sortAns;

        //de mayor a menor
        if (sortAns==1){
            
            HeapSortD(logsR);
            for (auto el : logsR) {
            cout << el << endl;
            }


        //de menor a mayor
        } else if (sortAns==2){

            HeapSortA(logsR);
            for (auto el : logsR) {
            cout << el << endl;
            }
    }
}




//Solicite al usuario un identificador único del buque a buscar.
    cout << "inserte el identificador único del buque a buscar" << endl;
    cin >> ansSerie;

//Despliegue la información del buque solicitado en caso de que si exista

    //bst.printLog(ansSerie);

//Utilice un árbol binario de búsqueda para realizar la búsqueda del buque.


/*template<class T>
void BST<T>::findLog(NodeT<T>*aux, string ansSerie){
    int level = 0;

    if(aux != nullptr){
        findLog(aux->right, ansSerie);
        if(aux->data.ubi == ansSerie){
            cout << aux->data << endl;
        }
        findLog(aux->left, ansSerie);
    }

}

template<class T>
void BST<T>::printLog(string ansSerie){
    findLog(root, ansSerie);
}*/

    return 0;
}