#include <iostream>
#include <vector>
using namespace std;
#include "List.h"

//actividad 1.0
// realiza 3 funciones para sumar 3 numeros
// una con int, una con double y una con float

int sumInt(int a, int b, int c){
    return a + b + c;
}

double sumDouble(double a, double b, double c){
    return a + b + c;
}

float sumFloat(float a, float b, float c){
    return a + b + c;
}

string sumString(string a, string b, string c){
    return a + b + c;
}


template<class T>
T sumAnything(T a, T b, T c){
    return a + b + c;
}




int main(){


/*
int a1 = 9;
int a2 = 3;
int a3 = 5;
double b1 = 6.9;
double b2 = 4.20;
double b3 = 9.6;
float c1 = 1.2;
float c2 = 3.4;
float c3 = 5.6;
string d1 = "texto1";
string d2 = "texto2";
string d3 = "texto3";

cout << "Suma de int: " << sumInt(a1, a2, a3) << endl;
cout << "Suma de T: " << sumAnything(a1,a2,a3) << endl;

cout << "Suma de double: " << sumDouble(b1,b2,b3) << endl;
cout << "Suma de T: " << sumAnything(b1,b2,b3) << endl;

cout << "Suma de float: " << sumFloat(c1,c2,c3) << endl;
cout << "Suma de T: " << sumAnything(c1,c2,c3) << endl;

cout << "Suma de string: " << sumString(d1,d2,d3) << endl;
cout << "Suma de T: " << sumAnything(d1,d2,d3) << endl;
 */


List< vector<int> > list;
vector<int> list1 = {1,2,3,4,5};
vector<int> list2 = {6,7,8,9,10};

list.add(list1);
list.add(list2);
list.printVector();
List<int> list3(list1);
list.print();


    return 0;
}