#ifndef BST_h
#define BST_h

#include "NodeT.h"

template<class T>
class BST{
private:
    NodeT<T>* root;
public:
    BST();
    void insert(T data);
    bool find(T data);
    void remove(T data);
    void print();
};






#endif