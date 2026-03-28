#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> numbers = {1, 2, 3, 4, 5}; //used vector to store numbers
    for (int num : numbers) { //used for-each loop to iterate through the vector
        cout << num << " " <<endl;
         
    }
    numbers.push_back(6); //added a new number to the vector
    cout << "After adding a new number: " << endl;
 for (int num : numbers) { //used for-each loop to iterate through the vector again
        cout << num << " " <<endl;
    }    
    //GETTING SIZE OF VECTOR
    int size = sizeof(numbers) / sizeof(numbers[0]); //used sizeof to get the size of the vector
    cout << "Size of the vector: " << size << endl;

    //looping through an array with sizeof()
    int arr[] = {1, 2, 3, 4, 5}; //used an array to store numbers     
    for(int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) { //used sizeof to get the size of the array
        cout << arr[i] << " " <<endl;
    }
}