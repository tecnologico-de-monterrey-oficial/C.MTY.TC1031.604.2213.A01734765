#include <iostream>
using namespace std;

#include "Stack.h"

int main()
{
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);

    cout << stack.getTop() << endl;

    stack.pop();

    cout << stack.getTop() << endl;
    //stack.print();

    return 0;
}
