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
    delete top;
};

template<class T>
void Stack<T>::push(T data){
    top = new Node<T>(data);
    size++;
};

template<class T>
void Stack<T>::print() {


for (std::stack<int> dump = stack; !dump.empty(); dump.pop())
        std::cout << dump.top() << '\n';

    std::cout << "(" << stack.size() << " elements)\n";


}


template<class T>
bool Stack<T>::isEmpty(){
    return size == 0;
};

#endif