#include <iostream>
#include <vector>
using namespace std;


template <class T>
int iterativa(vector <T> list){
    int n = 0;
    for (int i=0 ; i<=list.size()-1 ; i++){
        if(list[i] % 2 != 0){
            n = n + list[i];
        }
    }
    return n;
}


template <class T>
int recursiva(vector <T> list){
    int n = 0;
    int i = 0;

    if (i>list.size()-1) {
      return n;
    } else {
        if(list[i] % 2 != 0){
            n = n + list[i];
            i++;
            return recursiva(list);
        } else {
            i++;
            return recursiva(list);
        }
  }
  return 0;
}




int main(){
vector<int> list = {5,7,10,20,35,42,63,70,93,100,120,130,140,150,155,167,168,169,200}; 
int n;
int m;

n = iterativa(list);
m = recursiva(list);
    cout << "Suma de impares iterativa: " << n << endl;
    cout << "Suma de impares recursiva: " << m << endl;

    return 0;
}






