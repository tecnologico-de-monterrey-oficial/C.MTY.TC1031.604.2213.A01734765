#include <iostream>
using namespace std;

int main()
{
int p = 5;
int *q;
q = &p;

   cout << "variable p= " << p << endl;
   cout << "variable &p= " << &p << endl;
   cout << "variable q= " << q << endl;
   cout << "variable *q= " << *q << endl;
   cout << "variable &q= " << &q << endl; 
p=10;
   cout << "variable p= " << p << endl;
   cout << "variable &p= " << &p << endl;
   cout << "variable q= " << q << endl;
   cout << "variable *q= " << *q << endl;
   cout << "variable &q= " << &q << endl;  
p=15;
q=new int(20);  
   cout << "variable p= " << p << endl;
   cout << "variable &p= " << &p << endl;
   cout << "variable q= " << q << endl;
   cout << "variable *q= " << *q << endl;
   cout << "variable &q= " << &q << endl;  
delete q;
   cout << "variable q= " << q << endl;
   cout << "variable *q= " << *q << endl;
   cout << "variable &q= " << &q << endl;  
    return 0;
}
