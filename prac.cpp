//student management system using struct,loops and arrays
#include <iostream>
using namespace std;
struct Student { //used struct to define a new data type called Student
    string name;
    int age;
    char grade;
};
int main(){
    Student students[3]; //used an array of structs to store multiple students
    for(int i = 0; i < 3; i++){ //used a for loop to get the details of each student from the user
        cout << "Enter name of student " << i + 1 << ": ";
        getline(cin, students[i].name); //used getline to get the name of the student from the user and store it in the name member of the struct
        cout << "Enter age of student " << i + 1 << ": ";
        cin >> students[i].age; //used cin to get the age of the student from the user and store it in the age member of the struct
        cout << "Enter grade of student " << i + 1 << ": ";
        cin >> students[i].grade; //used cin to get the grade of the student from the user and store it in the grade member of the struct
        cin.ignore(); //used cin.ignore() to ignore the leftover newline character after reading age and grade
    }
    cout << "Student Details:" << endl; //used cout to print a message before printing the details of each student
    for(int i = 0; i < 3; i++){ //used a for loop to print the details of each student
        cout << "Name: " << students[i].name << endl; //used cout to print the name of each student
        cout << "Age: " << students[i].age << endl; //used cout to print the age of each student
        cout << "Grade: " << students[i].grade << endl; //used cout to print the grade of each student
    }
    /*//search for a student by name
    string searchName;
    cout << "Enter the name of the student to search: ";
    getline(cin, searchName); //used getline to get the name of the student to search
    bool found = false; //used a boolean variable to keep track of whether the student was found or not
    for(int i = 0; i < 3; i++){ //used a for loop to search for the student
        if(students[i].name == searchName){ //used an if statement to check if the name of the student matches the search name
            cout << "Student found!" << endl; //used cout to print a message indicating that the student was found
            cout << "Name: " << students[i].name << endl; //used cout to print the name of the student
            cout << "Age: " << students[i].age << endl; //used cout to print the age of the student
            cout << "Grade: " << students[i].grade << endl; //used cout to print the grade of the student
            found = true; //set the found variable to true
            break; //used break to exit the loop once the student is found
        }
        else { //used an if statement to check if the student was not found
        cout << "Student not found!" << endl; //used cout to print a message indicating that the student was not found
    }*/
    return 0;
}