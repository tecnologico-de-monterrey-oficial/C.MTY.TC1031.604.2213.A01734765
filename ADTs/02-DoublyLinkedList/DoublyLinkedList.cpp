#include <iostream>
using namespace std;

#include "DoublyLinkedList.h"

int main()
{
    
    DoublyLinkedList<int> list;

    list.append(5);
    list.append(10);
    list.appendLeft(15);
    list.appendLeft(20);
    list.print();
    list.printReverse(); 
    try {
        list.deleteAt(3);
        list.deleteAt(0);
        list.print();
        list.deleteAt(0);
        list.deleteAt(0);
        list.print();
        list.deleteAt(0);

    } catch(out_of_range &error) {
        cout << error.what() << endl;
    }
    
 
    return 0;
}
