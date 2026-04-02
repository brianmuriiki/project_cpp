#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;
class miniBank{
private:
    string accountHolder;
    double balance;
    string accountNumber;
    string accountType;
    string password;

    int pin;
public:
    miniBank() {
        accountHolder = "";
        balance = 0.0;
    }
    void createAccount() {
        cout << "Enter account holder name: ";
        getline(cin, accountHolder);
        cout << "Enter account number: ";
        cin >> accountNumber;
        cout << "Enter account type (savings/checking): ";
        cin >> accountType;
        cout << "Create a password: ";
        cin >> password;
        cout << "Confirm password: ";
        string confirmPassword;
        cin >> confirmPassword;
        if (password != confirmPassword) {
            cout << "Passwords do not match. Account creation failed.\n";
            return;
        }
        cout << "Set a 4-digit PIN: ";
        cin >> pin;
        if (pin < 1000 || pin > 9999) {
            cout << "Invalid PIN. Account creation failed.\n";
            return;
        }
        // Save account details to file
        ofstream file("accounts.txt", ios::app);
        if (file.is_open()) {
            time_t now = time(0);
            tm *ltm = localtime(&now);
            file << "Account Holder: " << accountHolder << endl;
            file << "Account Number: " << accountNumber << endl;
            file << "Account Type: " << accountType << endl;
            file << "Balance: " << balance << endl;
            file << "Date: "
                 << 1900 + ltm->tm_year << "-"
                 << 1 + ltm->tm_mon << "-"
                 << ltm->tm_mday << endl;
            file << "Time: "
                 << ltm->tm_hour << ":"
                 << ltm->tm_min << ":"
                 << ltm->tm_sec << endl;
            file << "----------------------" << endl;
            file.close();
        }
        cout << "Account created successfully.\n";
    }
    void deposit() {
        double amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        if (amount <= 0) {
            cout << "Invalid amount. Deposit failed.\n";
            return;
        }
        balance += amount;
        cout << "Deposit successful. New balance: " << balance << endl;
        // Update account details in file
        ofstream file("accounts.txt", ios::app);
        if (file.is_open()) {
            time_t now = time(0);
            tm *ltm = localtime(&now);
            file << "Account Holder: " << accountHolder << endl;
            file << "Account Number: " << accountNumber << endl;
            file << "Account Type: " << accountType << endl;
            file << "Balance: " << balance << endl;
            file << "Date: "
                 << 1900 + ltm->tm_year << "-"
                 << 1 + ltm->tm_mon << "-"
                 << ltm->tm_mday << endl;
            file << "Time: "
                 << ltm->tm_hour << ":"
                 << ltm->tm_min << ":"
                 << ltm->tm_sec << endl;
            file << "----------------------" << endl;
            file.close();
        }
    }
    void withdraw() {
        double amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        if (amount <= 0 || amount > balance) {
            cout << "Invalid amount. Withdrawal failed.\n";
            return;
        }
        balance -= amount;
        cout << "Withdrawal successful. New balance: " << balance << endl;
        // Update account details in file
        ofstream file("accounts.txt", ios::app);
        if (file.is_open()) {
            time_t now = time(0);
            tm *ltm = localtime(&now);
            file << "Account Holder: " << accountHolder << endl;
            file << "Account Number: " << accountNumber << endl;
            file << "Account Type: " << accountType << endl;
            file << "Balance: " << balance << endl;
            file << "Date: "
                 << 1900 + ltm->tm_year << "-"
                 << 1 + ltm->tm_mon << "-"
                 << ltm->tm_mday << endl;
            file << "Time: "
                 << ltm->tm_hour << ":"
                 << ltm->tm_min << ":"
                 << ltm->tm_sec << endl;
            file << "----------------------" << endl;
            file.close();
        }
    }
    void displayAccountDetails() {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: " << balance << endl;
    }
    void changePassword() {
        string currentPassword;
        cout << "Enter current password: ";
        cin >> currentPassword;
        if (currentPassword != password) {
            cout << "Incorrect password. Password change failed.\n";
            return;
        }
        cout << "Enter new password: ";
        string newPassword;
        cin >> newPassword;
        cout << "Confirm new password: ";
        string confirmPassword;
        cin >> confirmPassword;
        if (newPassword != confirmPassword) {
            cout << "Passwords do not match. Password change failed.\n";
            return;
        }
        password = newPassword;
        cout << "Password changed successfully.\n";
    }
    void changePin() {
        int currentPin;
        cout << "Enter current PIN: ";
        cin >> currentPin;
        if (currentPin != pin) {
            cout << "Incorrect PIN. PIN change failed.\n";
            return;
        }
        cout << "Enter new 4-digit PIN: ";
        int newPin;
        cin >> newPin;
        if (newPin < 1000 || newPin > 9999) {
            cout << "Invalid PIN. PIN change failed.\n";
            return;
        }
        pin = newPin;
        cout << "PIN changed successfully.\n";
    }
    // login function to authenticate user
    bool login() {
        string inputAccountNumber, inputPassword;
        cout << "Enter account number: ";
        cin >> inputAccountNumber;
        cout << "Enter password: ";
        cin >> inputPassword;
        if (inputAccountNumber == accountNumber && inputPassword == password) {
            cout << "Login successful.\n";
            return true;
             //timestamp for the login
             time_t now = time(0);
             tm *ltm = localtime(&now);
             ofstream logFile("accounts.txt", ios::app);
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
            cout << "Invalid account number or password.\n";
            return false;
        }
    }
    //bank statement function to display all transactions and account details with timestamps
        void bankStatement() {
        ifstream file("accounts.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                cout << line << endl;
            }
            file.close();
        } else {
            cout << "Unable to open file.\n";
        }
    }

};

//a system you are allowed to create account first then login to access the account details and perform transactions like deposit and withdraw. You can also change your password and pin. All transactions and account details are logged with timestamps in a file named accounts.txt.
int main() {
    miniBank bank;
    int choice;

    do {
        cout << "\nMINI BANKING SYSTEM" << endl;
        cout << "--------------------" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cin.ignore(); // to clear the newline character from the input buffer
                bank.createAccount();
                break;

            case 2:
                if (bank.login()) {
                    int transactionChoice;
                    do {
                        cout << "\nTRANSACTIONS" << endl;
                        cout << "------------" << endl;
                        cout << "1. Deposit" << endl;
                        cout << "2. Withdraw" << endl;
                        cout << "3. Display Account Details" << endl;
                        cout << "4. Change Password" << endl;
                        cout << "5. Change PIN" << endl;
                        cout << "6. Bank Statement" << endl;
                        cout << "7. Logout" << endl;
                        cout << "Enter choice: ";
                        cin >> transactionChoice;

                        switch (transactionChoice) {
                            case 1:
                                bank.deposit();
                                break;

                            case 2:
                                bank.withdraw();
                                break;

                            case 3:
                                bank.displayAccountDetails();
                                break;

                            case 4:
                                bank.changePassword();
                                break;

                            case 5:
                                bank.changePin();
                                break;
                            case 6:
                                bank.bankStatement();
                                break;

                            case 7:
                                cout << "Logged out successfully.\n";
                                break;

                            default:
                                cout << "Invalid choice.\n";
                        }
                    } while (transactionChoice != 7);
                }
                break;

            case 3:
                cout << "Exiting the system. Have a nice Time\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 3);

    return 0;
}

