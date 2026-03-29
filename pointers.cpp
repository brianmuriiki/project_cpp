//pointers
#include <iostream>
using namespace std;
    int main() {
    //creating a pointer
string name = "John"; //used a string variable to store a name
string *ptr = &name; //used a pointer to store the address of the name variable
cout << "Name: " << name << endl; //used cout to print the value of
cout << "name address: " << &name << endl; //used cout to print the address of name
cout << "Pointer: " << ptr << endl; //used cout to print the value of the pointer (address of name)#

//dereferencing a pointer
cout << "Dereferenced pointer: " << *ptr << endl; //used dereference operator

//modifying the value of name using the pointer
*ptr = "Jane"; //used dereference operator to change the value of name through the pointer
cout << "Name: " << name << endl; //used cout to print the new

//memory size

cout << "Size of name variable: " << sizeof(name) << " bytes" << endl; //used sizeof to get the size of the name variable
   //new
string *ptr2 = new string; //used new operator to dynamically allocate memory for a string
*ptr2 = "Hello"; //used dereference operator to assign a value to the dynamically
 
return 0;
}