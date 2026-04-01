//generic_calculator.cpp
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
template <typename T, typename U>
class Calculator {
public:
    auto add(T a, U b) {
        return a + b;
    }

    auto subtract(T a, U b) {
        return a - b;
    }

    auto multiply(T a, U b) {
        return a * b;
    }

    auto divide(T a, U b) {
        if (b != 0)
            return a / b;
        else {
            cout << "Error: Division by zero!" << endl;
            return 0.0; // Return 0 or throw an exception as needed
        }
    }

    //save calculation history to file
    void saveHistory(const string& history) {
        ofstream file("calculation_history.txt", ios::app); // Open file in append mode
        if (file.is_open()) {
            file << history << endl;
            //time stamp the history
            time_t now = time(0);
            tm *ltm = localtime(&now);
            file << "Date: "
                 << 1900 + ltm->tm_year << "-"
                 << 1 + ltm->tm_mon << "-"
                 << ltm->tm_mday << endl;
            file << "Time: "
                 << ltm->tm_hour << ":"
                 << ltm->tm_min << ":"
                 << ltm->tm_sec << endl;
            file.close();
        } else {
            cout << "Unable to open file." << endl;
        }
    }
};

int main() {
    Calculator<int, double> calc;
    int choice;
    do {
        cout << "\nGENERIC CALCULATOR" << endl;
        cout << "------------------" << endl;
        cout << "1. Add" << endl;
        cout << "2. Subtract" << endl;
        cout << "3. Multiply" << endl;
        cout << "4. Divide" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input." << endl;
            continue;
        }

        int a;
        double b;

        switch (choice) {
            case 1:
                cout << "Enter two numbers: ";
                cin >> a >> b;
                cout << "Result: " << calc.add(a, b) << endl;
                calc.saveHistory(to_string(a) + " + " + to_string(b) + " = " + to_string(calc.add(a, b)));
                break;

            case 2:
                cout << "Enter two numbers: ";
                cin >> a >> b;
                cout << "Result: " << calc.subtract(a, b) << endl;
                calc.saveHistory(to_string(a) + " - " + to_string(b) + " = " + to_string(calc.subtract(a, b)));
                break;

            case 3:
                cout << "Enter two numbers: ";
                cin >> a >> b;
                cout << "Result: " << calc.multiply(a, b) << endl;
                calc.saveHistory(to_string(a) + " * " + to_string(b) + " = " + to_string(calc.multiply(a, b)));
                break;

            case 4:
                cout << "Enter two numbers: ";
                cin >> a >> b;
                if (b != 0) {
                    cout << "Result: " << calc.divide(a, b) << endl;
                    calc.saveHistory(to_string(a) + " / " + to_string(b) + " = " + to_string(calc.divide(a, b)));
                } else {
                    cout << "Error: Division by zero!" << endl;
                    calc.saveHistory(to_string(a) + " / " + to_string(b) + " = Error: Division by zero!");
                }
                break;
            }
    } while (choice != 5);
    cout << "Exiting..." << endl;
    return 0;
}