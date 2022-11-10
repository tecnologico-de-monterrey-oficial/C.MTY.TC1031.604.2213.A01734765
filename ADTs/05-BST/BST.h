#ifndef BST_h
#define BST_h

#include "NodeT.h"

template<class T>
class BST{
private:
    NodeT<T>* root;
    void printTree(NodeT<T>* aux, int level);//hace que la impresión sea en arbol
    int howManyChildren(NodeT<T>* aux);
public:
    BST();
    void insert(T data);//inserta un nodo nuevo
    bool find(T data);//encuentra el valor de un nodo
    void remove(T data);//remueve el primer nodo que encuentre con el valor que escribas
    void print();//imprime
    bool isEmpty();//checa si esta vacio el arbol
    void order(int type);//da el orden 
    int whatLevelIAm(T data);//busca en que nivel está un valor
};

template<class T>
BST<T>::BST() {
    root = nullptr;
}

template<class T>
int BST<T>::howManyChildren(NodeT<T>* aux){
    if (aux->left == nullptr && aux->right == nullptr){
        return 0;
    } else {
        if(aux->left != nullptr && aux->right != nullptr){
            return 2;
        } else {
            return 1;
        }
    }
}

template<class T>
void BST<T>::insert(T data) {
    if (isEmpty()) {
        root = new NodeT<T>(data);
    } else {
        NodeT<T>* aux = root;
        while (aux != nullptr) {
            if (data < aux->data) {
                if (aux->left == nullptr) {
                    aux->left = new NodeT<T>(data);
                    return;
                } else {
                    aux = aux->left;
                }
            // else 
            } else {
                if (aux->right == nullptr) {
                    aux->right = new NodeT<T>(data);
                    return;
                } else {
                    aux = aux->right;
                }
            }
        }
    }
/*    if(isEmpty()){//si está vacio
        root = new NodeT<T>(data);

    }else{//si no está vacio
        NodeT<T>*aux = root;
        
        if(data < aux->data){//si es menor a root
            if(aux->left==nullptr){
                aux->left = new NodeT<T>(data);
                return;
            }else{
                aux=aux->left;
            }
        }





        }else{//si es mayor a root
        if(data > aux->data){
            if(aux->right==nullptr){
                aux->right = new NodeT<T>(data);
                return;
            }else{
                aux=aux->right;
            }
        }
    }*/
}




template<class T>
bool BST<T>::find(T data) {
    NodeT<T>* aux = root;
    while (aux != nullptr) {
        if (aux->data == data) {
            return true;
        } else {
            if (data < aux->data) {
                aux = aux->left;
            } else {
                aux = aux->right;
            }   
        }
    }
    return false;
}


template<class T>
void BST<T>::remove(T data) {
    if (!isEmpty()) {
        NodeT<T>* aux = root;
        if (data == root->data) {
            switch (howManyChildren(root)) {
            case 0: // No tiene hijos
                root = nullptr;
                delete aux;    
                break;
            case 1: // tiene 1 hijo
                root->right == nullptr ? root = root->left : root = root->right;
                // if (aux->right == nullptr) {
                //     root = aux->left;
                // } else {
                //     root = aux->right;
                // }
                // Borramos aux
                delete aux;   
                break; 
            case 2: // tiene 2 hijos
                NodeT<T>* auxBigLeft = aux->left;
                if (auxBigLeft->right == nullptr) {
                    aux->data = auxBigLeft->data;
                    aux->left = auxBigLeft->left;
                    delete auxBigLeft;
                } else {
                    NodeT<T>* auxPa = aux;
                    while (auxBigLeft->right != nullptr) {
                        auxPa = auxBigLeft;
                        auxBigLeft = auxBigLeft->right;
                    }
                    aux->data = auxBigLeft->data;
                    auxPa->right = auxBigLeft->left;
                    delete auxBigLeft;
                }
                break;
            }
        } else {// El nodo que voy a remover no es root
            NodeT<T>* auxPa = root;
            data < root->data ? aux = root->left : aux = root->right;
            while (aux != nullptr) {
                if (aux->data == data) {
                    switch (howManyChildren(aux)) {
                    case 0: // No tiene hijos
                        data < auxPa->data ? auxPa->left = nullptr : auxPa->right = nullptr; 
                        delete aux;
                        break;               
                    case 1: // Tiene 1 hijo
                        if (data < auxPa->data) {
                            aux->left != nullptr ? auxPa->left = aux->left : auxPa->left = aux->right;
                        } else {
                            aux->left != nullptr ? auxPa->right = aux->left : auxPa->right = aux->right;
                        }
                        delete aux;
                        break; 
                    case 2: // Tiene 2 hijos
                        NodeT<T>* auxBigLeft = aux->left;
                        if (auxBigLeft->right == nullptr) {
                            aux->data = auxBigLeft->data;
                            aux->left = auxBigLeft->left;
                            delete auxBigLeft;
                        } else {
                            NodeT<T>* auxPa = aux;
                            while (auxBigLeft->right != nullptr) {
                                auxPa = auxBigLeft;
                                auxBigLeft = auxBigLeft->right;
                            }
                            aux->data = auxBigLeft->data;
                            auxPa->right = auxBigLeft->left;
                            delete auxBigLeft;
                        }
                        break; 
                    }
                    return;
                } else {
                    auxPa = aux;
                    data < aux->data ? aux = aux->left : aux = aux->right;
                } 
            }
            throw invalid_argument("El valor a borra no se encuentra en el BST");
        }
    } else {
        throw invalid_argument("El valor a borra no se encuentra en el BST");
    }
}

template<class T>
void BST<T>::printTree(NodeT<T>*aux, int level){
    if(aux != NULL){
        printTree(aux->right, level+1);
        for (int i=0 ; i<level ; i++){
            cout << " ";
        }
        cout << aux->data << endl;
        printTree(aux->left, level+1);
    }
}

template<class T>
void BST<T>::print() {
    if(!isEmpty()){
        int level = 0;
        cout << endl;
        printTree(root, level);
        cout << endl;
    }else {
        cout << endl << "the BST is empty" << endl << endl;
    }
}

template<class T>
bool BST<T>::isEmpty(){
    return root == nullptr;
}

#endif