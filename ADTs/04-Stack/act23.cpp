#include <iostream>
using namespace std;

#include "Stack.h"

int main()
{
int ans;
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);

    stack.print();

cout<< "¿Que metodo quieres usar? (1=pop,2=push,3=top)" << endl;
cin >> ans;
    if(ans==1){
        stack.pop();

    } else if(ans==2){
        int n;
        cout<< "escribe un numero" << endl;
        cin >> n;
        stack.push(n);

    } else if(ans==3){
        cout << stack.getTop() << endl;
    }

    return 0;
}