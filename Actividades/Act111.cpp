//Act 1.1.1
//Ernesto Poisot Avila A01734765

#include <iostream>
using namespace std;



int fibonacciIterativo(int n) {
  if (n == 1) {
    return 1;
  } else {
    if (n == 2) {
      return 1;
    } else {
      int f1=1;
      int f2=1;
      for (int i=3; i<n; i++) {
        int aux = f2;
        f2 = f1 + f2;
        f1 = aux;
      }
      return f1 + f2;
    } 
  }
}

//-------------------------------------------------------------------------------------------------------

int fibonacciRecursivo(int n) {
  if (n==1 || n==2) {
      return 1;
  } else {
      return fibonacciRecursivo(n-1) + fibonacciRecursivo(n-2);
  }
}

//-------------------------------------------------------------------------------------------------------

int bacteriaIterativo(int dias) {
  int bacterias = 1;
  for(int d=1;d<=dias; d++) {
    bacterias = bacterias * (1+ (3.78-2.34));
  }
  return bacterias;
}

//-------------------------------------------------------------------------------------------------------

int bacteriasRecursivo(int dias) {
  if (dias == 0) {
    return 1;
  } else {
    return bacteriasRecursivo(dias-1)*(1+(3.78-2.34));
  }
}

//-------------------------------------------------------------------------------------------------------
 
double interesIterativo(int dias) {
  if (dias == 0) {
    return 1;
  } else {
    return bacteriasRecursivo(dias-1)*(1+(3.78-2.34));
  }
}

//-------------------------------------------------------------------------------------------------------

double interesRecursivo(int meses, double saldo) {
  if (meses == 0) {
    return saldo;
  } else {
    return interesRecursivo(meses-1, saldo)*(1+.1875);
  }
}

//-------------------------------------------------------------------------------------------------------

int potenciaIterativa(int x, int y) {
  int potencia = 1;
  for(int i=1; i<=y; i++) {
    potencia = potencia * x;
  }
  return potencia;
}

//-------------------------------------------------------------------------------------------------------

int potenciaRecursiva(int x, int y) {
  if (y==1) {
  return x;
  } else {
    return x * potenciaRecursiva(x, y-1);
  }
}

//-------------------------------------------------------------------------------------------------------


int main() {

int n=10
int saldo=1000
t << "fibonacci iterativo: " << fibonacciIterativo(n) << endl;
t << "fibonacci recursivo: " << fibonacciRecursivo(n) << endl;
t << "bacterias iterativo: " << bacteriasIterativo(n) << endl;
t << "bacterias recursivo: " << bacteriasRecursivo(n) << endl;
t << "interes iterativo: " << interesIterativo(n, saldo) << endl;
t << "interes recursivo: " << interesRecursivo(n, saldo) << endl;
int x = 2;
int y = 8;
t << "potencias iterativa: " << potenciaIterativa(x, y) << endl;
t << "potencias recursiva: " << potenciaRecursiva(x, y) << endl;

return 0;
}
