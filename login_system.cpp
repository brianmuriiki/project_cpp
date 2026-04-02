#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

// login system
class LoginSystem {
private:
    string username;
    string password;

public:
    // constructor
    LoginSystem() {
        username = "";
        password = "";
    }

    // validate username
    bool validateUsername(string username) {
        if (username.length() < 5 || username.length() > 15) {
            return false;
        }

        for (char c : username) {
            if (!isalnum(c)) {
                return false;
            }
        }

        return true;
    }

    // validate password
    bool validatePassword(string password) {
        if (password.length() < 8) {
            return false;
        }

        bool hasUpper = false;
        bool hasLower = false;
        bool hasDigit = false;

        for (char c : password) {
            if (isupper(c))
                hasUpper = true;
            else if (islower(c))
                hasLower = true;
            else if (isdigit(c))
                hasDigit = true;
        }

        return hasUpper && hasLower && hasDigit;
    }

    // register user
    void registerUser() {
        cout << "Enter username: ";
        cin >> username;

        if (!validateUsername(username)) {
            cout << "Invalid username. Use 5-15 letters/numbers only.\n";
            return;
        }

        cout << "Enter password: ";
        cin >> password;

        if (!validatePassword(password)) {
            cout << "Invalid password. Must contain uppercase, lowercase and number.\n";
            return;
        }

        ofstream file("users.txt", ios::app);

        if (file.is_open()) {
            file << username << "," << password << endl;

            time_t now = time(0);
            tm *ltm = localtime(&now);

            file << "Registration date: "
                 << 1900 + ltm->tm_year << "-"
                 << 1 + ltm->tm_mon << "-"
                 << ltm->tm_mday << endl;

            file << "Registration time: "
                 << ltm->tm_hour << ":"
                 << ltm->tm_min << ":"
                 << ltm->tm_sec << endl;

            file << "----------------------" << endl;

            file.close();

            cout << "User registered successfully.\n";
        }
        else {
            cout << "Unable to open file.\n";
        }
    }

    // login user
    void loginUser() {
        string inputUsername, inputPassword;

        cout << "Enter username: ";
        cin >> inputUsername;

        cout << "Enter password: ";
        cin >> inputPassword;

        ifstream file("users.txt");

        bool found = false;
        string line;

        if (file.is_open()) {
            while (getline(file, line)) {
                size_t pos = line.find(',');

                if (pos != string::npos) {
                    string fileUsername = line.substr(0, pos);
                    string filePassword = line.substr(pos + 1);

                    if (fileUsername == inputUsername && filePassword == inputPassword) {
                        found = true;
                        break;
                    }
                }
            }

            file.close();

            if (found) {
                cout << "Login successful.\n";

                // write login history
                ofstream logFile("users.txt", ios::app);

                time_t now = time(0);
                tm *ltm = localtime(&now);

                logFile << "Login date: "
                        << 1900 + ltm->tm_year << "-"
                        << 1 + ltm->tm_mon << "-"
                        << ltm->tm_mday << endl;

                logFile << "Login time: "
                        << ltm->tm_hour << ":"
                        << ltm->tm_min << ":"
                        << ltm->tm_sec << endl;

                logFile << "----------------------" << endl;

                logFile.close();
            }
            else {
                cout << "Invalid username or password.\n";
            }
        }
        else {
            cout << "Unable to open file.\n";
        }
    }
};

int main() {
    LoginSystem log;
    int choice;

    do {
        cout << "\nLOGIN SYSTEM\n";
        cout << "----------------------\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                log.registerUser();
                break;

            case 2:
                log.loginUser();
                break;

            case 3:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 3);

    return 0;
}