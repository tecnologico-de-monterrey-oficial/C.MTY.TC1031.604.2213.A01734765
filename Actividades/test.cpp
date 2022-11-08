#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <ctime>
#include <stdio.h>
#include <sys/time.h>
using namespace std;






//-------------------------------------------------------------


// Función que lee del teclado todos los valores que
// almacenará en el arreglo
// concepto muy importante - paso de parámetros por referencia - tu y Yo somos uno mismo
// el argumento correspondiente es el que se modifica directamente
void leerArreglo(int arrA[], int size){
   int val;
cout << "escribe los valores del arreglo"  <<endl;
   for(int i=0 ; i <= size ; i++){     
      cin >> val;
      arrA[i] = val;
   }
}

// Función que despliega el contenido del arreglo
//    - cada elemento en un renglón diferente  y
// además calcula y despliega la suma y promedio de todos los elementos del arreglo
// ver casos de prueba opcion 1
void sumaYpromedioArreglo(int arrA[], int size){
   for (int i = 0; i <= size; i++) {
      cout << arrA[i] <<endl;
   }
   
int sum=0;
   
   for(int i=0 ; i <= size ; i++){
      sum = sum + arrA[i];
   }

   
cout << "Total = " << sum <<endl;
cout << "Promedio = " << (float)sum/(float)(size + 1) <<endl;

}

// Función que despliega los valores pares del arreglo
//    - cada elemento en un renglón diferente  y
//      calcula y despliega  la suma y promedio de los valores pares del arreglo
//      Si el arreglo no tiene valores pares la función muestra
//          "No hubo valores pares en el arreglo\n"
// ver casos de prueba opcion 2
void sumaValoresPares(int arrA[], int size){

   for(int i=0 ; i <= size ; i++){
      if(arrA[i]%2==0){
         cout << arrA[i] << endl;
      }
   }
   
int sumPar=0;
int n=0;

   for(int i=0 ; i <= size ; i++){
      if(arrA[i]%2==0){
        sumPar=sumPar + arrA[i];
        n++;
      }
   } 
   

   if(sumPar==0){
      cout << "No hubo valores pares en el arreglo\n" << endl;
   }else {
      cout << "Total = " << sumPar << endl;
      cout << "Promedio = " <<  (float)sumPar/(float)n << endl;
   }
   
}

// Función reporteAlumnos - despliega en pantalla el nombre de los alumnos que tuvieron
// una calificación igual o superior a la recibida en el parámetro de entrada calificacion.
// Posteriormente muestra el Total de alumnos que cumplieron usando  "Total = "
// Si ningún alumno cumple se muestra - "No hubo alumnos"
// ver casos de prueba opcion 3
void reporteAlumnos(string arrNombres[], int arrCalificaciones[], int size, int calificacion){
   int total=0;

   for(int i=0 ; i <= size ; i++){
      if(calificacion <= arrCalificaciones[i] ){
        total++;
        cout << total << " ";
        cout << arrNombres[i] << " ";
        cout << arrCalificaciones[i] << endl;
      }
    }

    if (total != 0){
        cout << "Total = " << total << endl;
    }else{
        cout << "No hubo alumnos" << endl;
    }
}


int main() {
    int arrB[4];
    // Inicialización de arreglos desde código
    string arrNombres[12] = {"Felipe","Natalia","Gustavo","Victoria", "Debanhi", "Paulina", "Vicente", "Ana Paula", "Gerardo", "Sergio", "Cho", "Gaby"};
    int arrCalificaciones[12] = {110,110,100,100,100,110,120,100,110,110,100,105};
    int size = 4;
    int opcion;
    int calificacion;
    
    // leer la opcion a ejecutar
    cout << "escriba opcion: " << endl;
    cin >> opcion;
    
    // solo Si es opcion 1 o 2 llamar a la función que lee 5 valores enteros del teclado
   if(opcion==1 || opcion==2){
      leerArreglo(arrB, size);
   }
   
   
   if(opcion==1){ // si la opcion es 1 llamar a la función sumaYpromedioArreglo(arrB, size)
      sumaYpromedioArreglo(arrB, size);
   }else if(opcion==2){// si no Si la opcion es 2 llamar a la función sumaValoresPares(arrB, size)
      sumaValoresPares(arrB, size);
   }else if(opcion==3){// si no Si la opcion es 3 leer calificación y llamar a la función      reporteAlumnos(arrNombres, arrCalificaciones, 12, calificacion)
      cout << "escriba la calificacion: " << endl;
      cin >> calificacion;
      reporteAlumnos(arrNombres, arrCalificaciones, 12, calificacion);
   }else {// si no es alguna de las opciones desplegar "opcion incorrecta"
          cout << "opcion incorrecta" << endl;
   }
    
    return 0;
}
















