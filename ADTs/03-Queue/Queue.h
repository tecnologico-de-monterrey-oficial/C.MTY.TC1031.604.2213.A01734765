#ifndef Queue_h
#define Queue_h

#include "Node.h"

template<class T>
class Queue {
    private:
        Node<T>* front;
        int size;
    public:
        Queue(); //este construye la fila
        void push(T data);//agrega elemento a la fila
        T pop(); //este elimina el primer elemento
        T getFront(); //regresa el valor del primer elemento
        void print(); //imprimir fila
        bool isEmpty();
        
        
}; 


//este construye la fila
template<class T>
Queue<T>::Queue(){
    front = nullptr;
    size = 0;
}; 

//agrega elemento a la fila
template<class T>
void Queue<T>::push(T data){
    
    if (isEmpty()) {
        front = new Node<T>(data);
    } else {
        Node<T>* aux = front;
        while (aux->next != nullptr) {
            aux = aux->next;
        }
        aux->next = new Node<T>(data);
    }
    size++;

};

//este elimina el primer elemento
template<class T>
T Queue<T>::pop(){

}; 
 
//regresa el valor del primer elemento
template<class T>
T Queue<T>::getFront(){

}; 

template<class T>
void Queue<T>::print() {
    Node<T>* aux = front;
    while (aux != nullptr) {
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
}

template<class T>
bool Queue<T>::isEmpty(){
    return size == 0;
}

#endif