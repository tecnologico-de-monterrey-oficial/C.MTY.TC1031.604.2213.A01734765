#ifndef Stack_h
#define Stack_h

template <class T>
class Stack{
    private:
        Node<T>* top;
        int size;
    public:
        Stack();
        T getTop();//valor de arriba de stack
        T pop(); //elimina el valor de arriba de stack
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

};

template<class T>
T Stack<T>::pop(){
    
};

template<class T>
void Stack<T>::push(T data){
    
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