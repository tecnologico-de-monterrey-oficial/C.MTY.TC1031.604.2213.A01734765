#include <iostream>
using namespace std;

#include "Node.h"

int main()
{
//crear apuntador a un espacio en memoria tipo nodo
Node<int>* head;
head = new Node<int> (5);
//primer nodo
cout << "valor de head: " << head << endl; //dirección del primer nodo
cout << "valor de head->data: " << head->data << endl;//valor del primer nodo
cout << "valor de head->next: " << head->next << endl;//el apuntador del primer nodo, da 0 porque no hay mas entonces es NULL

head->next = new Node<int>(10);//se le asigna direccion al apuntador del primer nodo
//primer nodo
cout << "primer nodo: " << endl;
cout << "valor de head: " << head << endl;
cout << "valor de head->data: " << head->data << endl;
cout << "valor de head->next: " << head->next << endl;
//segundo nodo (primera opcion) encadenando pointers
cout << "segundo nodo (primera opcion): " << endl;
cout << "valor de head->next->data: " << head->next->data << endl;
cout << "valor de head->next->next: " << head->next->next << endl;
//segundo nodo (segunda opcion) usando un aux para no escribir la cadena
Node<int>*aux=head->next;
cout << "segundo nodo (segunda opcion): " << endl;
cout << "valor aux->data: " << aux->data << endl;
cout << "valor de aux->next: " << aux->next << endl;



    return 0;
}
