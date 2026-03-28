#include <iostream>
using namespace std;
//enum is a special type that represents a group of constants
   // enum Color {RED = 23, GREEN = 3, BLUE = 45}; //used enum to define a new data type
    
int main() {
    /*enum Color myColor = RED; //used enum to create a variable of type Color and assign it a value
    cout << "My color is: " << myColor << endl; //used cout to print the value of myColor*/

    //references
    string meal = "fries";
    string &food = meal; //used reference to create an alias for the meal variable
    cout << "Meal: " << meal << endl; //used cout to print the value
    cout << "Food: " << food << endl; //used cout to print the value
    //changing the value of meal will also change the value of food because they are references to the same variable
 
    meal = "burger"; //used assignment operator to change the value of meal
    cout << "Meal: " << meal << endl; //used cout to print the new
    cout << "Food: " << food << endl; //used cout to print the new value of food

    //memmory addresses
    cout << "Address of meal: " << &meal << endl; //used address-of operator to print the address of meal
    cout << "Address of food: " << &food << endl; //used address-of operator to print the address of food
    return 0;
}