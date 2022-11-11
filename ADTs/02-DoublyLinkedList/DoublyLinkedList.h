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
        DoublyLinkedList(); // Constructor por default
        void append(T data); // Agrega un elemento al final de la lista
        void appendLeft(T data); // Agrega un elemento al principio de la lista
        void deleteAt(int index); // Elimina un elemento en el índice dado
        int findData(T data); // Regresa el indice donde se encontruentra el valor buscado
        T getData(int index); // Regresa el valor que se encuentra en el índice dado
        T& operator[](int index); // Regresa el valor que se encuentra en el índice dado
        void insert(int index, T data); // Inserta un elemento después del índice dado
        void deleteData(T data); // Elimina el elemento dado (El primero que encuentre)
        void print(); // Imprime la lista de izquierda a derecha
        void printReverse(); // Imprime la lista de derecha a izquierda
        bool isEmpty();
        void updateData(T data1, T data2);//Actualiza el primer elemento que sea igual al valor recibido como parámetro con el valor del dato nuevo recibido como parámetro.
        void updateAt(int index, T data);//Actualiza un elemento en una posición recibida como parámetro con el valor de un dato recibido como parámetro.
        bool operator=(DoublyLinkedList<T> list); // Regresa el valor que se encuentra en el índice dado


};


template <class T>
DoublyLinkedList<T>::DoublyLinkedList(){
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

template <class T>
void DoublyLinkedList<T>::updateAt(int index, T data){
    if (index >= 0 && index < size) {
        
        
        NodeD<T>* aux;
        if (index < size/2) {
            aux = head;
            int auxIndex = 0; 
            while (auxIndex < index) {
                aux = aux->next;
                auxIndex++;
            }   
        } else {
            aux = tail->prev;
            int auxIndex = size - 2; 
            while (auxIndex > index) {
                aux = aux->prev;
                auxIndex--;
            }   
        }
        aux->data=data;




    } else {
        throw out_of_range("El índice es inválido");
    }
}

template <class T>
void DoublyLinkedList<T>::updateData(T data1, T data2){
    NodeD<T>* aux = head;
    int auxIndex = 0;
    while (aux != nullptr) {
        if (aux->data == data1) {
            aux->data=data2;
        } else {
            aux = aux-> next;
            auxIndex++;
        }
    }
    throw out_of_range("El dato no se encuentra");
}


// Agrega un elemento al final de la lista
template<class T>
void DoublyLinkedList<T>::append(T data) {
    tail = new NodeD<T>(data, nullptr, tail);
    if (head == nullptr) {
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
    if (tail == nullptr) {
        tail = head;
    } else {
        head->next->prev = head;
    }
    size++;
}

// Elimina un elemento en el índice dado
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
            } else {
                if (index == size -1) {
                    NodeD<T>* aux = tail;
                    tail = tail->prev;
                    tail->next = nullptr;
                    delete aux;
                } else {
                    NodeD<T>* aux;
                    if (index < size/2) {
                        aux = head->next;
                        int auxIndex = 1; 
                        while (auxIndex < index) {
                            aux = aux->next;
                            auxIndex++;
                        }   
                    } else {
                        aux = tail->prev;
                        int auxIndex = size - 2; 
                        while (auxIndex > index) {
                            aux = aux->prev;
                            auxIndex--;
                        }   
                    }
                    aux->prev->next = aux->next;
                    aux->next->prev = aux->prev;
                    delete aux;
                }
            }
        
        }
        size--;
    } else {
        throw out_of_range("El índice es inválido");
    }
}

// Regresa el indice donde se encontruentra el valor buscado
template<class T>
int DoublyLinkedList<T>::findData(T data) {
    NodeD<T>* aux = head;
    int auxIndex = 0;
    while (aux != nullptr) {
        if (aux->data == data) {
            return auxIndex;
        } else {
            aux = aux-> next;
            auxIndex++;
        }
    }
    // Si nos salimos del ciclo es que no enconrtamos el valor y genermoas una excepción
    throw out_of_range("El dato no se encuentra");
}

// Regresa el valor que se encuentra en el índice dado
template<class T>
T DoublyLinkedList<T>::getData(int index) {
    if (index >= 0 && index < size) {
        NodeD<T>* aux;
        if (index < size/2) {
            aux = head;
            int auxIndex = 0; 
            while (auxIndex < index) {
                aux = aux->next;
                auxIndex++;
            }   
        } else {
            aux = tail->prev;
            int auxIndex = size - 2; 
            while (auxIndex > index) {
                aux = aux->prev;
                auxIndex--;
            }   
        }
        return aux->data;
    } else {
        throw out_of_range("El índice es inválido");
    }
}

// Regresa el valor que se encuentra en el índice dado
template<class T>
T& DoublyLinkedList<T>::operator[](int index) {
    if (index >= 0 && index < size) {
        NodeD<T>* aux;
        if (index < size/2) {
            aux = head;
            int auxIndex = 0; 
            while (auxIndex < index) {
                aux = aux->next;
                auxIndex++;
            }   
        } else {
            aux = tail->prev;
            int auxIndex = size - 2; 
            while (auxIndex > index) {
                aux = aux->prev;
                auxIndex--;
            }   
        }
        return aux->data;
    } else {
        throw out_of_range("El índice es inválido");
    }
}

// Inserta un elemento después del índice dado
template<class T>
void DoublyLinkedList<T>::insert(int index, T data) {
    if (index >= 0 && index < size) {
        if (index < size / 2) {
            int auxIndex = 0;
            NodeD<T>* aux = head;
            while (auxIndex < index) {
                aux = aux->next;
                auxIndex++;
            }
            NodeD<T>* newNode = new NodeD<T>(data, aux->next, aux);
            aux->next = newNode;
            newNode->next->prev = newNode;
        } else {
            if (index == size - 1) {
                tail->next = new NodeD<T>(data, nullptr, tail);
                tail = tail->next;
            } else {
                int auxIndex = size - 2;
                NodeD<T>* aux = tail->prev;
                while (auxIndex > index) {
                    aux = aux->prev;
                    auxIndex--;
                }
                NodeD<T>* newNode = new NodeD<T>(data, aux->next, aux);
                aux->next = newNode;
                newNode->next->prev = newNode;
            }
        }
        size++;
    } else {
        throw out_of_range("El índice es inválido");
    }
}

// Elimina el elemento dado (El primero que encuentre)
template<class T>
void DoublyLinkedList<T>::deleteData(T data) {
    NodeD<T>* aux = head;
    if (aux->data == data) {
        if (size == 1) {
            head = nullptr;
            tail = nullptr;
            delete aux;
        } else {
            head = head->next;
            head->prev = nullptr;
            delete aux;
        }
        size--;
    } else {
        aux = aux->next;
        while (aux != nullptr) {
            if (aux->data == data) {
                if (aux->next == nullptr) {
                    tail = aux->prev;
                    tail->next = nullptr;
                    delete aux;
                } else {
                    aux->prev->next = aux->next;
                    aux->next->prev = aux->prev;
                    delete aux;
                }
                size--;
                return;
            } else {
                aux = aux->next;
            }
        }
        throw out_of_range("El dato no se encuentra");
    }
}

// Imprime la lista de izquierda a derecha
template <class T>
void DoublyLinkedList<T>::print(){
    NodeD<T>* aux = head;
    while (aux != nullptr) {
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
}

// Imprime la lista de derecha a izquierda
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