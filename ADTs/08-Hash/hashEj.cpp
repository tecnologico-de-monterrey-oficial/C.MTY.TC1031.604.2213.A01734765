#include <iostream>
#include <fstream>
using namespace std;

#include "hashMat.h"

int main(){
    
    HashMat mat;
    fstream file ("matriculas.txt");
    string matricula;




    mat.print();
    mat.deleteMatricula("A0696969");

    if (mat.findMatricula("A0696969")) {
        cout << "si la encontramos" << endl;
    } else {
        cout << "no la encontramos" << endl; 
    }
           
    return 0;
}
