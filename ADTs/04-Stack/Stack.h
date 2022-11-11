#ifndef Stack_h
#define Stack_h

#include "Node.h"

template <class T>
class Stack{
    private:
        Node<T>* top;
        int size;
    public:
        Stack();
        T getTop();//valor de arriba de stack
        T pop(); //elimina el valor de arriba de stack y dice cual se borró
        void push(T data);//agrega elemento a la fila
        void print(); //imprimir fila
        void reversePrint();//imprimir al reves
        bool isEmpty();
};


template<class T>
Stack<T>::Stack(){
    top = nullptr;
    size = 0;
};

template<class T>
T Stack<T>::getTop(){
    return top->data;
};

template<class T>
T Stack<T>::pop(){
    if (!isEmpty()) {
        Node<T>* aux = top;
        T auxData = aux->data;
        top = top->next;
        delete aux;
        size--;
        return auxData;
    } else {
        throw out_of_range("La fila esta vacía");
    }
};

template<class T>
void Stack<T>::push(T data){
        if (isEmpty()) {
        top = new Node<T>(data);
    } else {
        Node<T>* aux = top;
        while (aux->next != nullptr) {
            aux = aux->next;
        }
        aux->next = new Node<T>(data);
    }
    size++;
};

template<class T>
void Stack<T>::print(){
    Node<T>* aux = top;
    while (aux != nullptr) {
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
};

template<class T>
void Stack<T>::reversePrint(){
    
};

template<class T>
bool Stack<T>::isEmpty(){
    return size == 0;
};

#endif