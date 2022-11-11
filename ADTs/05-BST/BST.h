#ifndef BST_h
#define BST_h

#include "NodeT.h"
#include "Queue.h"


template<class T>
class BST{
private:
    NodeT<T>* root;
    void printTree(NodeT<T>* aux, int level);
    int howManyChildren(NodeT<T>* aux);
    void preOrden(NodeT<T>* root);
    void inOrden(NodeT<T>* root);
    void postOrden(NodeT<T>* root);
    void preOrdenConv(NodeT<T>* root);
    void inOrdenConv(NodeT<T>* root);
    void postOrdenConv(NodeT<T>* root);
    void nivelPorNivel();
    

public:
    BST();
    void insert(T data);//inserta un nodo nuevo
    bool find(T data);//encuentra el valor de un nodo
    void remove(T data);//remueve el primer nodo que encuentre con el valor que escribas
    void print();//imprime
    bool isEmpty();//checa si esta vacio el arbol
    void orden(int type);//da el orden 
    int whatLevelIAm(T data);//busca en que nivel está un valor
    int height();
    void ancestors(T data);
};

template<class T>
BST<T>::BST() {
    root = nullptr;
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
void BST<T>::preOrden(NodeT<T>* aux){
    //condicion central para salir recursividad
    if(aux != nullptr){
      //visita el nodo raiz del arbol
        cout << aux->data << " " ;
      //recorre preordel arbol izquierdo
        preOrden(aux->left);            
      // preorder arbol derecho  
        preOrden(aux->right);       

    }
}

template<class T>
void BST<T>::inOrden(NodeT<T>* aux){
    if(aux != nullptr){
        inOrden(aux->left);
        cout << aux->data << " " ;
        inOrden(aux->right);  
    }
}

template<class T>
void BST<T>::postOrden(NodeT<T>* aux){
    if(aux != nullptr){
        postOrden(aux->left);
        postOrden(aux->right); 
        cout << aux->data << " " ;

                
    }
}

template<class T>
void BST<T>::preOrdenConv(NodeT<T>* aux){
    if(aux != nullptr){
        cout << aux->data << " " ;
        preOrden(aux->right);            
        preOrden(aux->left);       

    }
}

template<class T>
void BST<T>::inOrdenConv(NodeT<T>* aux){
    if(aux != nullptr){
        inOrden(aux->right);
        cout << aux->data << " " ;
        inOrden(aux->left);  
    }
}

template<class T>
void BST<T>::postOrdenConv(NodeT<T>* aux){
    if(aux != nullptr){
        postOrden(aux->right);
        postOrden(aux->left); 
        cout << aux->data << " " ;

                
    }
}

template<class T>
void BST<T>::nivelPorNivel(){
    Queue<NodeT<T>*> queue;
    //meter nodo raiz a una fila
    queue.push(root);    
    //mientras la fila no se vacie
    while(!queue.isEmpty()){
        NodeT<T>*aux = queue.pop();
        //sacar un nodo de la fila y procesarlo
        cout << aux->data << " ";
        //meter a la fila a los hijos del nodo procesado (si estos existen)
        if(aux->left != nullptr){
            queue.push(aux->left);
        }
        if(aux->right != nullptr){
            queue.push(aux->right);
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

template<class T>
void BST<T>::orden(int type){
    switch (type)
    {
    case 1: //1=pre orden
        preOrden(root);
        
        break;

    case 2: //2=in orden
        inOrden(root);
        break;
    
    case 3: //3=post order
        postOrden(root);
        break;

    case 4: //4=pre orden converso
        preOrdenConv(root);
        break;

    case 5: //5=in orden converso
        inOrdenConv(root);
        break;
    
    case 6: //6=post order converso
        postOrdenConv(root);
        break;

    case 7: //7= nivel por nivel
        nivelPorNivel();
        break;



    default:
        break;
    }
}

template<class T>
int BST<T>::whatLevelIAm(T data){
        NodeT<T>* aux = root;
        int nivel = 1;
    while (aux != nullptr) {
        if (aux->data == data) {
            return nivel;
        } else {
            if (data < aux->data) {
                nivel++;
                aux = aux->left;
            } else {
                nivel++;
                aux = aux->right;
            }   
        }
    }
    return nivel;
}

template<class T>
int BST<T>::height(){
    
}


template<class T>
void BST<T>::ancestors(T data){

}
#endif