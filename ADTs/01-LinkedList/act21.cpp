#include <iostream>
#include <string>
using namespace std;

#include "LinkedList.h"

int main()
{
int ans;
LinkedList<int> list;

    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.append(6);

    list.print();

cout<< "¿Que metodo quieres usar? (1=CREATE,2=READ,3=UPDATE,4=DELETE)" << endl;
cin >> ans;
    
    
    if(ans==1){
    int n;    
    cout<< "escribe un numero" << endl;
    cin >> n;
    list.append(n);
    list.print();

    } else if(ans==2){
    int n;
    cout<< "escribe un numero" << endl;
    cin >> n;
    cout << list.getData(n) << endl;

    } else if(ans==3){
    int n;
    int n1;
    cout<< "escribe el indice y el valor" << endl;
    cin >> n;
    cin >> n1;
    list.update(n,n1);
    list.print();

    } else if(ans==4){
    int n;   
    cout<< "escribe el indice" << endl;
    cin >> n;
    list.deleteAt(n);
    list.print();
    }

    return 0;
}