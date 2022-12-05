#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

#include "Graph.h"
#include "HashPuerto.h"


void puerto(Graph<string> rutaPuerto){
    string org;
    string sal;
    int sino;

    cout << "Teclee un puerto de origen" << endl;
    cin >> org;
    cout << "Teclee un puerto de destino" << endl;
    cin >> sal;
    cout << endl;

    rutaPuerto.Dijkstra(org,sal);

    while(true){
        cout << endl << endl << "Quiere comprobar otro puerto? (1 - si, 2 - no)" << endl;
        cin >> sino;
        if(sino == 1){
            puerto(rutaPuerto);
            return;
        }
        else if(sino == 2){
            return;
        }
        else{
            cout << "Valor invalido" << endl;
        }
    }
}

int main(){   
    ifstream arch;
    string ansFileName;
    string org;
    string sal;
    int dat = 0;
    int millas = 0;
    int cont = 0;


    cout << "inserte el nombre del archivo que se leerá: " << endl;
    cin >> ansFileName;

    arch.open(ansFileName);


    vector< Vertex<string> > rutas;
    Hash puertos;
    arch >> dat;
    while(dat > cont){
        arch >> org >> sal >> millas;
        rutas.push_back(Vertex <string> (org,sal,millas));
        cont++;
    }
    arch >> dat;
    cont = 0;
    while(dat > cont){
        arch >> org;
        puertos.addDato(org);
        cont++;
    }
    Graph<string> PurtoRuta(puertos, rutas);

    puerto(PurtoRuta);

    cout << endl << "Terminando programa" << endl;
    return 0;
}
