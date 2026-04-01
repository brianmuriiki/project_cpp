#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

class Employee {
protected:
    string name;
    int id;
    double salary;
    int payrollNumber;
    int tax;
    int allowances;

public:
    Employee() {
        name = "";
        id = 0;
        salary = 0;
        payrollNumber = 0;
        tax = 0;
        allowances = 0;
    }

    // Input employee details
    void input() {
        cin.ignore();
        cout << "Enter employee name: ";
        getline(cin, name);

        cout << "Enter employee ID: ";
        cin >> id;

        cout << "Enter salary: ";
        cin >> salary;

        cout << "Enter tax: ";
        cin >> tax;

        cout << "Enter allowances: ";
        cin >> allowances;

        // Generate payroll number
        time_t now = time(0);
        tm *ltm = localtime(&now);

        payrollNumber = id + ltm->tm_sec + ltm->tm_min + ltm->tm_hour;

        cout << "Payroll Number Generated: " << payrollNumber << endl;
    }

    // Save to file
    void saveToFile() {
        ofstream file("payroll.txt", ios::app);

        if (file.is_open()) {
            time_t now = time(0);
            tm *ltm = localtime(&now);

            file << "Name: " << name << endl;
            file << "ID: " << id << endl;
            file << "Salary: " << salary << endl;
            file << "Tax: " << tax << endl;
            file << "Allowances: " << allowances << endl;
            file << "Net Salary: " << salary - tax + allowances << endl;
            file << "Payroll Number: " << payrollNumber << endl;

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

            cout << "Payroll saved successfully." << endl;
        } else {
            cout << "Unable to open file." << endl;
        }
    }

    // Show all payroll records
    void showPayroll() {
        ifstream file("payroll.txt");

        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                cout << line << endl;
            }
            file.close();
        } else {
            cout << "Unable to open file." << endl;
        }
    }

    // Search employee
    void searchEmployee() {
        ifstream file("payroll.txt");

        if (file.is_open()) {
            string searchTerm;
            cin.ignore();
            cout << "Enter employee ID or payroll number: ";
            getline(cin, searchTerm);

            string line;
            bool found = false;

            while (getline(file, line)) {
                if (line.find(searchTerm) != string::npos) {
                    cout << line << endl;

                    for (int i = 0; i < 8; i++) {
                        getline(file, line);
                        cout << line << endl;
                    }

                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Employee not found." << endl;
            }

            file.close();
        }
    }

    // Delete employee by ID
    void deleteEmployee(int searchId) {
        ifstream file("payroll.txt");
        ofstream temp("temp.txt");

        if (file.is_open() && temp.is_open()) {
            string line;
            bool found = false;
            bool skip = false;

            while (getline(file, line)) {
                if (line == "ID: " + to_string(searchId)) {
                    found = true;
                    skip = true;
                    continue;
                }

                if (skip && line == "----------------------") {
                    skip = false;
                    continue;
                }

                if (!skip) {
                    temp << line << endl;
                }
            }

            file.close();
            temp.close();

            remove("payroll.txt");
            rename("temp.txt", "payroll.txt");

            if (found)
                cout << "Employee deleted successfully." << endl;
            else
                cout << "Employee not found." << endl;
        }
    }

    // Edit employee
    void editEmployee(int searchId) {
        deleteEmployee(searchId);

        cout << "Enter new employee details:" << endl;
        input();
        saveToFile();
    }
};

int main() {
    Employee emp;
    int choice;

    do {
        cout << "\nPAYROLL MANAGEMENT SYSTEM" << endl;
        cout << "--------------------------" << endl;
        cout << "1. Add Employee Payroll" << endl;
        cout << "2. View All Payroll Records" << endl;
        cout << "3. Search Employee" << endl;
        cout << "4. Edit Employee" << endl;
        cout << "5. Delete Employee" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                emp.input();
                emp.saveToFile();
                break;

            case 2:
                emp.showPayroll();
                break;

            case 3:
                emp.searchEmployee();
                break;

            case 4: {
                int id;
                cout << "Enter employee ID to edit: ";
                cin >> id;
                emp.editEmployee(id);
                break;
            }

            case 5: {
                int id;
                cout << "Enter employee ID to delete: ";
                cin >> id;
                emp.deleteEmployee(id);
                break;
            }

            case 6:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice." << endl;
        }

    } while (choice != 6);

    return 0;
}