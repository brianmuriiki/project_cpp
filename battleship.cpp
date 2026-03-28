#include <iostream>
using namespace std;
int main() {
    //we are using multidimentional arrays to create a battleship game
    //we will use a 2D array to represent the game board
    bool ship[5][5] = {{0, 0, 0, 0, 0}, //used a 2D array to represent the game board
                       {0, 1, 1, 1, 0}, //used 1 to represent a ship and 0 to represent water
                       {0, 0, 0, 0, 0},
                       {0, 1, 1, 1, 0},
                       {0, 0, 0, 0, 0}};

    //we keep track of the number of hits and misses
    int hits = 0;
    int misses = 0;
    int numberofturns = 0;
    //we will use a loop to allow the player to make guesses
   /* for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << "Enter your guess (row and column): ";
            int row, col;
            cin >> row >> col; //used cin to get the player's guess
            if (ship[row][col] == 1) { //used if statement to check
                cout << "Hit!" << endl; //used cout to print a message if the player hits a ship
                hits++; //used increment operator to increase the number of hits
            } else {
                cout << "Miss!" << endl; //used cout to print a message if the player misses
                misses++; //used increment operator to increase the number of misses
            }
        }
    }
    cout << "Game over!" << endl; //used cout to print a message when the
    //game is over
    cout << "You had " << hits << " hits and " << misses << " misses." << endl; //used cout to print the number of hits and misses*/

    //we use a while loop to allow the player to keep guessing until they hit all the ships
    while (hits < 6) { //used while loop to allow the player to keep
        cout << "Selecting coordinates" << endl; //used cout to print a message when the player is selecting coordinates
        int row, col;
        //ask the player to enter the row guess
        cout << "Enter your row guess (0-4): ";
        cin >> row; //used cin to get the player's row guess
        //ask the player to enter the column guess
        cout << "Enter your column guess (0-4): ";
        cin >> col; //used cin to get the player's column guess
        if (ship[row][col] == 1) { //used if statement to check if the player's guess is a hit
            cout << "Hit!" << endl; //used cout to print a message if the player hits a ship
            hits++; //used increment operator to increase the number of hits
        } else {
            cout << "Miss!" << endl; //used cout to print a message if the player misses
            misses++; //used increment operator to increase the number of misses
        }
        numberofturns++;
    }
    cout << "Game over!" << endl; //used cout to print a message when the game is over
    cout << "You had " << hits << " hits and " << misses << " misses and took " << numberofturns << " turns." << endl;
    return 0;
}