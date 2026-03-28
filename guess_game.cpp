#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
 srand(static_cast<unsigned int>(time(nullptr))); // Seed the random number generator
    int numberToGuess = rand() % 100 + 1; // Generate a random number between 1 and 100
    int userGuess = 0;

    cout << "Welcome to the Guessing Game!" << endl;
    cout << "I have selected a number between 1 and 100. Can you guess it?" << endl;

    while (userGuess != numberToGuess) {
        cout << "Enter your guess: ";
        cin >> userGuess;

        if (userGuess < numberToGuess) {
            cout << "Too low! Try again." << endl;
        } else if (userGuess > numberToGuess) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You've guessed the number!" << endl;
        }
    }

    return 0;
}