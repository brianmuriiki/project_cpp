#include <iostream>
#include <string>
using namespace std;
int main() {
    int numguests;
    cout << "Enter the number of guests: ";
    cin >> numguests; //used cin to get the number of guests from the user

    if (numguests < 0) { //used if statement to check if the number of guests is negative
        cout << "Number of guests cannot be negative." << endl; //used cout to print an error message if the number of guests is negative
    } else if (numguests == 0) { //used else if statement to check if the number of guests is zero
        cout << "No guests are coming." << endl; //used cout to print a message if no guests are coming
    } else {
        cout << "Number of guests: " << numguests << endl; //used cout to print the number of guests
    }

    //create memory space for the names of the guests
    string* guestNames = new string[numguests]; //used new operator to dynamically allocate
    //memory for an array of strings to store the names of the guests
    //ignore the leftover newline character after reading numguests
    cin.ignore(); //used cin.ignore() to ignore the leftover newline character
    
    //get the names of the guests from the user
    for (int i = 0; i < numguests; i++) {
        cout << "Enter the name of guest " << i + 1 << ": ";
        getline(cin, guestNames[i]); //used getline to get the name of each guest from 
        //the user and store it in the guestNames array
    }

    cout << "Guest List:" << endl; //used cout to print a message before the guest list
    for (int i = 0; i < numguests; i++) {
        cout << guestNames[i] << endl; //used cout to print the name of each
        //guest from the guestNames array
    }

    delete[] guestNames; //used delete[] to free the dynamically allocated memory for the guestNames array
    return 0;
}