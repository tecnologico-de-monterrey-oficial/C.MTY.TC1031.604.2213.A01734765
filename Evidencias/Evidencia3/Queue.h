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


template<class T>
Queue<T>::Queue() {
    size = 0;
    front = nullptr;
}

template<class T>
void Queue<T>::push(T data) {
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
}

template<class T>
T Queue<T>::pop() {
    if (!isEmpty()) {
        Node<T>* aux = front;
        T auxData = aux->data;
        front = front->next;
        delete aux;
        size--;
        return auxData;
    } else {
        throw out_of_range("La fila esta vacía");
    }
}

template<class T>
T Queue<T>::getFront() {
    if (!isEmpty()) {
        return front->data;
    } else {
        throw out_of_range("La fila esta vacía");
    }
}

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
bool Queue<T>::isEmpty() {
    return size == 0;
}

#endif