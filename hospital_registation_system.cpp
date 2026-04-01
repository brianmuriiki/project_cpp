#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;
//patient registration system using file handling and class
class patient {
protected:
    string name;
    int age;
    int patientId;
    string ailment;
    int roomNumber;
public:
    // default constructor
    patient() {
        name = "";
        age = 0;
        patientId = 0;
        ailment = "";
        roomNumber = 0;
    }
    // input patient details
    void registerpatient() {
        cin.ignore(); //to clear the input buffer before taking string input
        cout << "Patient Registration" << endl;
        cout << "--------------------" << endl;
        cout << "Enter name: ";
        getline(cin, name);

        cout << "Enter age: ";
        cin >> age;

        cout << "Enter patient ID: ";
        cin >> patientId;
        cin.ignore(); //to clear the input buffer before taking string input
        cout << "Enter ailment: ";
        getline(cin, ailment);
        cout << "Enter room number: ";
        cin >> roomNumber;
    }

    // save patient details to file
    void saveToFile() {
        ofstream file("patients.txt", ios::app); //open file in append mode

        if (file.is_open()) {
            time_t now = time(0);
            tm *ltm = localtime(&now);

            file << "Name: " << name << endl;
            file << "Age: " << age << endl;
            file << "Patient ID: " << patientId << endl;
            file << "Ailment: " << ailment << endl;
            file << "Room Number: " << roomNumber << endl;

            file << "Admission Date: "
                 << 1900 + ltm->tm_year << "-"
                 << 1 + ltm->tm_mon << "-"
                 << ltm->tm_mday << endl;

            file << "Admission Time: "
                 << ltm->tm_hour << ":"
                 << ltm->tm_min << ":"
                 << ltm->tm_sec << endl;

               file << "----------------------" << endl;
            file.close();
        } else {
            cout << "Unable to open file." << endl;
        }
    }

    // read patient details from file
    void showpatient() {
        ifstream file("patients.txt");

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
    //add doctor details to patient record
    void addDoctorDetails() {
        ofstream file("patients.txt", ios::app); //open file in append mode

        if (file.is_open()) {
            string doctorName;
            string specialization;

            cout << "Doctor Assignment" << endl;
            cout << "-----------------" << endl;
            cout << "Enter doctor's name: ";
            cin.ignore(); //to clear the input buffer before taking string input
            getline(cin, doctorName);

            cout << "Enter doctor's specialization: ";
            getline(cin, specialization);

            file << "Doctor Name: " << doctorName << endl;
            file << "Specialization: " << specialization << endl;
            file.close();
        } else {
            cout << "Unable to open file." << endl;
        }
    }

   
    //search patient by ID or name
   void searchPatient() {
    ifstream file("patients.txt");

    if (file.is_open()) {
        string searchTerm;
        cout << "Enter patient ID or name to search: ";
        cin.ignore();
        getline(cin, searchTerm);

        string line;
        bool found = false;
        bool printRecord = false;

        while (getline(file, line)) {

            // check if current line contains searched term
            if (line.find(searchTerm) != string::npos) {
                found = true;
                printRecord = true;
            }

            // print full record once match starts
            if (printRecord) {
                cout << line << endl;
            }

            // stop printing when record ends
            if (printRecord && line == "----------------------") {
                printRecord = false;
            }
        }

        if (!found) {
            cout << "Patient not found." << endl;
        }

        file.close();
    } else {
        cout << "Unable to open file." << endl;
    }
}

    //discharge patient and remove their record from file
    void dischargePatient() {
        ifstream file("patients.txt");
        ofstream temp("temp.txt");
        string line;
        bool found = false;
        bool skip = false;
        int searchId;
        cout << "Enter patient ID to discharge: ";
        cin >> searchId;
        while (getline(file, line)) {
            if (line == "Patient ID: " + to_string(searchId)) {
                found = true;
                skip = true;
                cout << "Patient discharged successfully." << endl;
                cout << "Room number " << roomNumber << " is now available." << endl;
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
        remove("patients.txt");
        rename("temp.txt", "patients.txt");
        if (!found) {
            cout << "Patient not found." << endl;
        }
    }

    //update patient record
    void updatePatient() {
        ifstream file("patients.txt");
        ofstream temp("temp.txt");
        string line;
        bool found = false;
        bool skip = false;
        int searchId;
        cout << "Enter patient ID to update: ";
        cin >> searchId;
        while (getline(file, line)) {
            if (line == "Patient ID: " + to_string(searchId)) {
                found = true;
                skip = true;

                cout << "Enter new patient details:" << endl;
                registerpatient(); //call the function to input new patient details
                saveToFile(); //save the new details to file
                continue;
            }

        }
    }

};

int main(){
    patient p;
    int choice;
    do {
        cout << "\nHOSPITAL REGISTRATION SYSTEM" << endl;
        cout << "----------------------------" << endl;
        cout << "1. Register patient" << endl;//doctor details are added after patient registration to ensure that the doctor is assigned to a patient
        cout << "2. Show patient details" << endl;
        cout << "3. Search patient by ID or name" << endl;
        cout << "4. Discharge patient" << endl;
        cout << "5. Update patient record" << endl;
        cout << "6. Exit" << endl;
        cout << "==============================" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                p.registerpatient();
                p.saveToFile();
                p.addDoctorDetails();
                cout << "Patient registered successfully." << endl;
                break;
            case 2:
                p.showpatient();
                break;
            case 3:
                p.searchPatient();
                break;
            case 4:
                p.dischargePatient();
               
                break;
            case 5:
                p.updatePatient();
                p.addDoctorDetails(); //update doctor details after updating patient record
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 6);
}

            
        



