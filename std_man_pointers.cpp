#include <iostream>
using namespace std;
struct Student {
    string name;
    int age;
};
int main() {
    int n;
    cout << "Enter number of students: "<< endl;
    cin >>n;
    Student* std = new Student[n]; //dynamically allocate memory for a student struct
   
    for(int i = 0; i < n ; i++){
        cout << "Enter name and age of student " << i + 1 << ": ";
        cin >> std[i].name >> std[i].age; //accessing the members of the struct using pointer notation

    }
     cout << "\nStudents:\n";
       for(int i = 0; i < n ; i++){
        cout << "Name: " << std[i].name << ", Age: " << std[i].age << endl; //accessing the members of the struct using pointer notation
    }

    delete[] std; //deallocate the memory allocated for the student struct



     return 0;
}