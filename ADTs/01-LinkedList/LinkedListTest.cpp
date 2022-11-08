#include <iostream>
using namespace std;

#include "LinkedList.h"

int main()
{
    LinkedList<string> list;



    list.appendLeft("Z");
    list.print();
    list.append("A");
    list.append("B");
    list.append("C");
    list.appendLeft("Y");
    try{
        list.insert(2, "B");
    }catch(out_of_range &error){
        cout<<error.what()<<endl;
    }
    list.print();
    string aux= list.getData(10);
    try {
        string aux = list.getData(10);
        cout << "valor de la posición 2: " << aux << endl;
    }catch(out_of_range &error){
        cout << error.what() << endl;
    }
    list[0]= "X";
    cout << list[0] << endl;
    list.print();


    
    return 0;
}
