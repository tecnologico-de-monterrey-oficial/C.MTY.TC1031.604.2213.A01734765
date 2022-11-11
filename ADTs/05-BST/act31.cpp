#include <iostream>
using namespace std;

#include "BST.h"


int main()
{
    BST<int> bst;
    int ans;

    bst.insert(40);
    bst.insert(20);
    bst.insert(60);
    bst.insert(18);
    bst.insert(30);
    bst.insert(15);
    bst.insert(25);
    bst.print();

    cout<< "¿Que metodo quieres usar? (1=VISIT,2=HEIGHT,3=ANCESTORS,4=WHATLEVELAMI)" << endl;
    cin >> ans;
    
    
    if(ans==1){
    int n;    
    cout<< "elige parametro de entrada (1=Preorder2=Inorder,3=Postorder,4=Level by level" << endl;
    cin >> n;
    bst.orden(n);

    } else if(ans==2){

    cout << bst.height() << endl;

    } else if(ans==3){
    int n;    
    cout<< "escribe un numero" << endl;
    cin >> n;
    cout << bst.ancestors(n) << endl;

    } else if(ans==4){
    int n;   
    cout<< "escribe un numero" << endl;
    cin >> n;
    bst.whatLevelIAm(n);
    }





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

    cout << bst.whatLevelIAm(25) << endl;


    
    return 0;
}
