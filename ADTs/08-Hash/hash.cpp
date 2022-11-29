#include <iostream>
using namespace std;

int hashFuncion(string matricula){
  try {
    int numMatricula = stoi(matricula.substr(1,8));
    return numMatricula % 99;
    }catch(invalid_argument &e){
        cout << e.what() << endl;
    }
}


int main()
{
    
    cout << hashFuncion("A01734765") << endl;
    
    return 0;
}
