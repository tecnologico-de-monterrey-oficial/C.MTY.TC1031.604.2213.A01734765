#ifndef LinkedList_h
#define LinkedList_h


#include "Node.h"

template<class T>
class LinkedList {
private:
    Node<T>* head;
    int size;
public:
    LinkedList();
    void append(T data); // Agrega un elemento al final de la lista
    void appendLeft(T data); // Agrega un elemento al principio de la lista
    int findData(T data); // * Regresa el indice donde se encontruentra el valor buscado
    T getData(int index); // * Regresa el valor que se encuentra en el índice dado
    T& operator[](int index); // ** Regresa el valor que se encuentra en el índice dado
    void insert(int index, T data); // *Inserta un elemento después del índice dado
    void deleteAt(int index); // *Elimina un elemento en el índice dado
    void deleteData(T data); // *Elimina el elemento dado (El primero que encuentre)
    void print();
    bool isEmpty();
};

template<class T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    size = 0;
}

// Agrega un elemento al final de la lista
template<class T>
void LinkedList<T>::append(T data) {

    if (isEmpty()) {
        head = new Node<T>(data);
    } else {
        Node<T>* aux = head;
        while (aux->next != nullptr) {
            aux = aux->next;
        }
        aux->next = new Node<T>(data);
    }
    size++;
}

// Agrega un elemento al principio de la lista
template<class T>
void LinkedList<T>::appendLeft(T data) {
    head = new Node<T>(data, head);
    size++;
}

// * Regresa el indice donde se encontruentra el valor buscado (checar si no se encuentra la data)
template<class T>
int LinkedList<T>::findData(T data) {
    
    Node<T>* aux = head;
    if (aux->data == data) {
        int index = 0;
        return index;

        } else {
            Node<T>* prevAux = head;
            aux = head->next;
            int auxIndex = 1;
            while (aux->data != data) {
                auxIndex++;
                prevAux = aux;
                aux = aux->next;
            }
            prevAux->next = aux->next;
            return auxIndex;
        }

}

// Regresa el valor que se encuentra en el índice dado
template<class T>
T LinkedList<T>::getData(int index) {
    if (index >= 0 && index < size) {
        Node<T>* aux = head;
        int auxIndex = 0;
        while (auxIndex < index) {
            auxIndex++;
            aux = aux->next;
        }
        return aux->data;
    } else {
        throw out_of_range("El índice es inválido");
    }
}

// Obtiene/Asigna un elemento a la lista
template<class T>
T& LinkedList<T>::operator[](int index) {
    if (index >= 0 && index < size) {
        Node<T>* aux = head;
        int auxIndex = 0;
        while (auxIndex < index) {
            auxIndex++;
            aux = aux->next;
        }
        return aux->data;
    } else {
        throw out_of_range("El índice es inválido");
    }
}

// *Elimina el elemento dado (El primero que encuentre)
template<class T>
void LinkedList<T>::deleteAt(int index) {
    if (index >= 0 && index < size) {
        Node<T>* aux = head;
        if (index == 0) {
            head = head->next;
            delete aux;
        } else {
            Node<T>* prevAux = head;
            aux = head->next;
            int auxIndex = 1;
            while (auxIndex < index) {
                auxIndex++;
                prevAux = aux;
                aux = aux->next;
            }
            prevAux->next = aux->next;
            delete aux;
        }
    } else {
        throw out_of_range("El índice es inválido");
    }
}

// *Elimina el elemento dado (El primero que encuentre)
template<class T>
void LinkedList<T>::deleteData(T data) {

        Node<T>* aux = head;
        if (aux->data == data) {
            head = head->next;
            delete aux;

        } else {
            Node<T>* prevAux = head;
            aux = head->next;
            int auxIndex = 1;
            while (aux->data != data) {
                auxIndex++;
                prevAux = aux;
                aux = aux->next;
            }
            prevAux->next = aux->next;
            delete aux;
        }

}

// *Inserta un elemento después del índice dado
template<class T>
void LinkedList<T>::insert(int index, T data) {
    if (index >= 0 && index < size) {
        Node<T>* aux = head; 
        int auxIndex = 0;
        while (auxIndex < index) {
            auxIndex++;
            aux = aux->next;
        }
        aux->next = new Node<T>(data, aux->next);
        size++;
    
    } else {
        throw out_of_range("El índice es inválido");
    }
}

template<class T>
void LinkedList<T>::print() {
    Node<T>* aux = head;
    while (aux != nullptr) {
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
}

template<class T>
bool LinkedList<T>::isEmpty() {
    return size == 0;
}

#endif