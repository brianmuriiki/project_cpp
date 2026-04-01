#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

class student {
protected:
    string name;
    int age;
    int id;
    string course;

public:
    // default constructor
    student() {
        name = "";
        age = 0;
        id = 0;
        course = "";
    }

    // input student details
    void input() {
        cin.ignore();

        cout << "Enter name: ";
        getline(cin, name);

        cout << "Enter age: ";
        cin >> age;

        cout << "Enter ID: ";
        cin >> id;

     

        cout << "Enter course: ";
        getline(cin, course);
    }

    // save student details
    void saveToFile() {
        ofstream file("students.txt", ios::app);

        if (file.is_open()) {
            time_t now = time(0);
            tm *ltm = localtime(&now);

            file << "Name: " << name << endl;
            file << "Age: " << age << endl;
            file << "ID: " << id << endl;
            file << "Course: " << course << endl;

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

            cout << "Student saved successfully." << endl;
        } else {
            cout << "Unable to open file." << endl;
        }
    }

    // display all students
    void readFromFile() {
        ifstream file("students.txt");

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

    // search student by ID
    void searchById(int searchId) {
        ifstream file("students.txt");

        if (file.is_open()) {
            string line;
            bool found = false;

            while (getline(file, line)) {
                if (line == "ID: " + to_string(searchId)) {
                    found = true;

                    cout << line << endl;

                    for (int i = 0; i < 4; i++) {
                        getline(file, line);
                        cout << line << endl;
                    }
                }
            }

            if (!found) {
                cout << "Student not found." << endl;
            }

            file.close();
        }
    }

    // delete student
    void deleteStudent(int searchId) {
        ifstream file("students.txt");
        ofstream temp("temp.txt");

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

        remove("students.txt");
        rename("temp.txt", "students.txt");

        if (found)
            cout << "Student deleted successfully." << endl;
        else
            cout << "Student not found." << endl;
    }

    // edit student record
    void editDetails(int searchId) {
        ifstream file("students.txt");
        ofstream temp("temp.txt");

        string line;
        bool found = false;
        bool skip = false;

        while (getline(file, line)) {
            if (line == "ID: " + to_string(searchId)) {
                found = true;
                skip = true;

                cout << "Enter new student details:" << endl;
                input();

                time_t now = time(0);
                tm *ltm = localtime(&now);

                temp << "Name: " << name << endl;
                temp << "Age: " << age << endl;
                temp << "ID: " << id << endl;
                temp << "Course: " << course << endl;

                temp << "Date: "
                     << 1900 + ltm->tm_year << "-"
                     << 1 + ltm->tm_mon << "-"
                     << ltm->tm_mday << endl;

                temp << "Time: "
                     << ltm->tm_hour << ":"
                     << ltm->tm_min << ":"
                     << ltm->tm_sec << endl;

                temp << "----------------------" << endl;

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

        remove("students.txt");
        rename("temp.txt", "students.txt");

        if (found)
            cout << "Student updated successfully." << endl;
        else
            cout << "Student not found." << endl;
    }

    // clear all records
    void clearFile() {
        ofstream file("students.txt");
        file.close();
        cout << "All records cleared." << endl;
    }
};

int main() {
    int choice;
    student s;

    do {
        cout << "\nSTUDENT RECORD SYSTEM" << endl;
        cout << "----------------------" << endl;
        cout << "1. Create student record" << endl;
        cout << "2. Display all records" << endl;
        cout << "3. Search by ID" << endl;
        cout << "4. Edit student record" << endl;
        cout << "5. Delete student record" << endl;
        cout << "6. Clear all records" << endl;
        cout << "7. Exit" << endl;
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
                s.input();
                s.saveToFile();
                break;

            case 2:
                s.readFromFile();
                break;

            case 3: {
                int searchId;
                cout << "Enter ID to search: ";
                cin >> searchId;
                s.searchById(searchId);
                break;
            }

            case 4: {
                int searchId;
                cout << "Enter ID to edit: ";
                cin >> searchId;
                s.editDetails(searchId);
                break;
            }

            case 5: {
                int searchId;
                cout << "Enter ID to delete: ";
                cin >> searchId;
                s.deleteStudent(searchId);
                break;
            }

            case 6:
                s.clearFile();
                break;

            case 7:
                cout << "Program exited successfully." << endl;
                break;

            default:
                cout << "Invalid choice." << endl;
        }

    } while (choice != 7);

    return 0;
}