#include <iostream>
using namespace std;


//suma iterativa
int sumaIterativa(int n){
int r = 0;
    for(int i=0 ; i<=n ; i++){
        r = r+i;
    }
return r;
}

//suma recursiva
int sumaRecursiva(int n){
  if (n == 1) {
    return 1;
  } else {
    return n + sumaRecursiva(n-1);
  }
}

//suma directa
double sumaDirecta(int n){

  return n * (   (double)n/(double)2  + 0.5 );
}



int main(){
int n;
cout << "escribe un número: " << endl;
cin >> n;

    cout<< "suma iterativa: " << sumaIterativa(n) <<endl;
    cout<< "suma recursiva: " << sumaRecursiva(n) <<endl;
    cout<< "suma directa: " << sumaDirecta(n) <<endl;
    return 0;
}
