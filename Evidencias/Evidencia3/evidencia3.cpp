#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

#include "Log.h"







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
vector<Log> logsM;
vector<Log> logsR;

//Solicite el nombre del archivo de entrada (Ej. canal.txt) y lo abra,
cout << "inserte el nombre del archivo que se leerá" << endl;
    cin >> ansFileName;

    ifstream file;
    file.open(ansFileName);

 
//almacenando los datos en dos listas (use la clase vector para crear las listas) una para los que entran 
//por el Mar Mediterráneo y otra para los buques que entran por el mar Rojo.


    while (file >> date >> time >> entry >> ubi){
        Log log(date, time, entry, ubi);
        if(entry=="M"){
            logsM.push_back(log);
        } else if(entry=="R")
            logsR.push_back(log);

    }

    cout << "Mediterraneo" << endl;
    printLogs(logsM);
    cout << "Rojo" << endl;
    printLogs(logsR);

//Ordene ambas listas de mayor a menor y de menor a mayor por UBI + Fecha + Hora (primero por UBI, al haber empate 
//ordenar por fecha y si persiste el empate por hora). Use el algoritmo de HeapSort para ordenar las listas.

//Despliegue la lista ordenada de acuerdo a la solicitud del usuario.
//Mar Mediterraneo
//de mayor a menor
//de menor a mayor
//Mar Rojo
//de mayor a menor
//de menor a mayor
//Solicite al usuario un identificador único del buque a buscar.
//Despliegue la información del buque solicitado en caso de que si exista
//Utilice un árbol binario de búsqueda para realizar la búsqueda del buque.
//Realice un menú con las diferentes opciones solicitadas en la actividad
    return 0;
}
