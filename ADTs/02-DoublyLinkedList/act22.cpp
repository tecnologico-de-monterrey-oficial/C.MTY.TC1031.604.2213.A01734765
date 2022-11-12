#include <iostream>
using namespace std;

#include "DoublyLinkedList.h"

int main()
{
int ans;
DoublyLinkedList<int> list;
    list.append(1);  
    list.append(2);  
    list.append(3);  
    list.append(4);  
    list.append(5);  
    list.append(6);  

    list.print();

cout<< "¿Que metodo quieres usar? (1=addFirst, 2=addLast, 3=deleteData, 4=deleteAt, 5=getData, 6=updateData, 7=updateAt, 8=findData, 9=sobrecarga operador[], 10=sobrecarga operador =)" << endl;
cin >> ans;
    if(ans==1){//Inserta un elemento al principio de la lista
        int n;
        cout<< "escribe un numero" << endl;
        cin >> n;
        list.appendLeft(n);  
        list.print();

    }else if(ans==2){//Inserta un elemento al final de la lista.
        int n;
        cout<< "escribe un numero" << endl;
        cin >> n;
        list.append(n);  
        list.print();

    }else if(ans==3){//	Borra el primer elemento que se encuentre en la lista igual al parámetro de entrada.
        int n;
        cout<< "escribe un numero" << endl;
        cin >> n;
        list.deleteData(n);
        list.print();

    }else if(ans==4){//Borra un elemento en una posición de la lista dada.
        int n;
        cout<< "escribe un numero" << endl;
        cin >> n;
        list.deleteAt(n);
        list.print();

    }else if(ans==5){//	Lee el valor de un dato de la lista, de acuerdo  con posición recibida como parámetro de entrada.
        int n;
        cout<< "escribe un numero" << endl;
        cin >> n;
        cout<<list.getData(n)<<endl;
        
    }else if(ans==6){//	Actualiza el primer elemento que sea igual al valor recibido como parámetro con el valor del dato nuevo recibido como parámetro.
        int n;
        int n1;
        cout<< "escribe indice y dato" << endl;
        cin >> n;
        cin >> n1;
        list.updateData(n,n1);
        list.print();

    }else if(ans==7){//Actualiza un elemento en una posición recibida como parámetro con el valor de un dato recibido como parámetro.
        int n;
        int n1;
        cout<< "escribe 2 datos" << endl;
        cin >> n;
        cin >> n1;
        list.updateAt(n,n1);
        list.print();

    }else if(ans==8){//	Busca un elemento en la lista.
        int n;
        cout<< "escribe un numero" << endl;
        cin >> n;
        cout<<list.findData(n)<<endl;   

    }else if(ans==9){//	Lee y/o actualiza un elemento en una posición dada.
        int n;
        cout<< "escribe un numero" << endl;
        cin >> n;
        cout<<list.operator[](n)<<endl;    

    }else if(ans==10){//Actualiza la lista con base en otra lista.
        
    }

    return 0;
}