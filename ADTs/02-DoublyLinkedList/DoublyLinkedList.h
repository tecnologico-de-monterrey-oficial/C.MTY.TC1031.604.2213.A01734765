#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

#include "NodeD.h"

template <class T>
class DoublyLinkedList {
    private:
        NodeD<T>* head;
        NodeD<T>* tail;
        int size;
    public:
        DoublyLinkedList();
        void append(T data); // Agrega un elemento al final de la lista
        void appendLeft(T data); // Agrega un elemento al principio de la lista
        void deleteAt(int index); // *Elimina un elemento en el índice dado

        void print(); //imprimir
        void printReverse(); //imprimir al reves
        bool isEmpty(); //esta vacio
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(){
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

template<class T>
void DoublyLinkedList<T>::append(T data) {
    tail = new NodeD<T>(data, nullptr, tail);
    if (head==nullptr) {
        head = tail;
    } else {
        tail->prev->next = tail;
    }
    size++;
}

// Agrega un elemento al principio de la lista
template<class T>
void DoublyLinkedList<T>::appendLeft(T data) {
    head = new NodeD<T>(data, head, nullptr);
    if (tail==nullptr) {
        tail = head;
    } else {
        head->next->prev = head;
    }
    size++;
}

template<class T>
void DoublyLinkedList<T>::deleteAt(int index) {
    if (index >= 0 && index < size) {
        if (size == 1) {
            NodeD<T>* aux = head;
            head = nullptr;
            tail = nullptr;
            delete aux;
        } else {
            if (index == 0) {
                NodeD<T>* aux = head;
                head = head->next;
                head->prev = nullptr;
                delete aux;
            }else {
                if(index == size-1){//en caso de que sea el ultimo
                    NodeD<T>* aux = tail;
                    tail = tail->prev;
                    head->next = nullptr;
                    delete aux;
                } else { //todo lo demás
                    NodeD<T>* aux;

                    if (index < size/2){//si está por la izquierda de la lista

                        aux = head->next;
                        int auxIndex = 1;
                        while (auxIndex < index){
                            aux = aux->next;
                            auxIndex++;
                        }
                    
                    } else{//si está por la derecha de la lista
                        aux = tail->prev;
                        int auxIndex = size - 2;
                        while (auxIndex > index){
                            aux = aux->prev;
                            auxIndex--;
                        } 
                    }

                    aux->prev = aux->next;
                    aux->next->prev = aux->prev;
                    delete aux;
                }
            }
        }



    } else {
        throw out_of_range("El índice es inválido");
    }
}

template <class T>
void DoublyLinkedList<T>::print(){
    NodeD<T>* aux = head;
    while (aux != nullptr) {
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
}

template <class T>
void DoublyLinkedList<T>::printReverse(){
    NodeD<T>* aux = tail;
    while (aux != nullptr) {
        cout << aux->data << " ";
        aux = aux->prev;
    }
    cout << endl;
}

template <class T>
bool DoublyLinkedList<T>::isEmpty(){
    return size == 0;
}

#endif