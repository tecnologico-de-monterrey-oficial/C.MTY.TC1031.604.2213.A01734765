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

cout<< "¿Que metodo quieres usar? (1=addFirst,2=addLast,3=deleteData, 4=deleteAt, 5=getData, 6=updateData, 7=updateAt, 8=findData, 9=sobrecarga operador[], 10=sobrecarga operador =)" << endl;
cin >> ans;
    if(ans==1){
        int n;
        cout<< "escribe un numero" << endl;
        cin >> n;
        list.append(n);  
        list.print();

    }else if(ans==2){
        int n;
        cout<< "escribe un numero" << endl;
        cin >> n;
        list.appendLeft(n);  
        list.print();

    }else if(ans==3){
        int n;
        cout<< "escribe un numero" << endl;
        cin >> n;
        list.deleteData(n);
        list.print();

    }else if(ans==4){
        int n;
        cout<< "escribe un numero" << endl;
        cin >> n;
        list.deleteAt(n);
        list.print();

    }else if(ans==5){
        int n;
        cout<< "escribe un numero" << endl;
        cin >> n;
        cout<<list.getData(n)<<endl;
        
    }else if(ans==6){
        int n;
        int n1;
        cout<< "escribe indice y dato" << endl;
        cin >> n;
        cin >> n1;
        list.updateData(n,n1);
        list.print();

    }else if(ans==7){
        int n;
        int n1;
        cout<< "escribe 2 datos" << endl;
        cin >> n;
        cin >> n1;
        list.updateAt(n,n1);
        list.print();

    }else if(ans==8){
        int n;
        cout<< "escribe un numero" << endl;
        cin >> n;
        cout<<list.findData(n)<<endl;   

    }else if(ans==9){
        int n;
        cout<< "escribe un numero" << endl;
        cin >> n;
        cout<<list.operator[](n)<<endl;    

    }else if(ans==10){
        
    }

    return 0;
}