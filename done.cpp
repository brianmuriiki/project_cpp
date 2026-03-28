#include <iostream>
#include <string>
using namespace std;
int main() {
    //multidimentional array
    //its an array of arrays
    //2D array
    string names[2][4] = {{"John", "Jane", "Jack", "Jill"}, //2 number of elements/rows and 4 number of elements/columns
                         {"Tom", "Tim", "Tina", "Tara"}}; //used a multidimensional array to store names
   //3D array
    int numbers[2][3][4] = {{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}, //2 number of elements/rows, 3 number of elements/columns and 4 number of elements/depth
                            {{13, 14, 15, 16}, {17, 18, 19, 20}, {21, 22, 23, 24}}}; //used a multidimensional array to store numbers

   cout << names[0][0] << endl; //used cout to print the first element of the first row of the names array
    cout << names[1][2] << endl; 
    cout << numbers[0][1][2] << endl; 
    cout << numbers[1][2][3] << endl;

    //change the value of an element in the array
    names[0][0] = "Johnny"; 
    cout << names[0][0] << endl; 

    //looping through a multidimensional array
    for(int i = 0; i < 2; i++) { 
        for(int j = 0; j < 4; j++) {
            cout << names[i][j] << " "; //used nested for loop to print all the elements of the names array
        }
        cout << endl;
    }
    //looping through a 3D array
    cout << "The numbers in the 3D array are: " << endl;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 4; k++) {
                cout << numbers[i][j][k] << " "; //used nested for loop to print all the elements of the numbers array
            }
            cout << endl;
        }
    }
    return 0;
}