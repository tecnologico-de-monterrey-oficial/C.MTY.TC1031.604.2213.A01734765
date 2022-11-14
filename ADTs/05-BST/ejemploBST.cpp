#include <iostream>
using namespace std;

#include "BST.h"


int main()
{
    BST<int> bst;

    bst.insert(40);
    bst.insert(20);
    bst.insert(60);
    bst.insert(18);
    bst.insert(30);
    bst.insert(15);
    bst.insert(25);
    bst.print();

    /*if(bst.find(30)){
        cout << "Se encontró" << endl;
    } else {
        cout << "NO se encontró" << endl;
    }

    try {
        bst.remove(50);
    }catch(invalid_argument &error){
        cout << error.what() << endl;
    }*/

    //bst.orden(1);

    //cout << bst.whatLevelIAm(25) << endl;

    cout << "---------------------" << endl;
    cout << bst.find(60) << endl;
    
    return 0;
}
