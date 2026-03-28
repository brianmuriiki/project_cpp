#include <iostream>
using namespace std;
int main() {
struct {//used to group related variables together
    string name;
    int age;
    char grade;
} student1, student2;
student1.name = "John"; //used dot operator to access the name member of the student struct
student1.age = 20; //used dot operator to access the age member of the student struct
student1.grade = 'A'; //used dot operator to access the grade member of the student struct
student2.name = "Jane"; //used dot operator to access the name member of the student struct
student2.age = 22; //used dot operator to access the age member of the student struct
student2.grade = 'B'; //used dot operator to access the grade member of the student struct
cout << "Name: " << student1.name << endl; //used cout to print the name
cout << "Age: " << student1.age << endl; //used cout to print the age
cout << "Grade: " << student1.grade << endl; //used cout to print the grade
cout << "Name: " << student2.name << endl; //used cout to print the name
cout << "Age: " << student2.age << endl; //used cout to print the age
cout << "Grade: " << student2.grade << endl; //used cout to print the grade
}

//using named struct
struct Student { //used struct to define a new data type called Student
    string name;
    int age;
    char grade;
};
int main() {
Student student3; //used the Student struct to create a new variable called student3
student3.name = "Jack"; //used dot operator to access the name member of the student
student3.age = 21; //used dot operator to access the age member of the student
student3.grade = 'A'; //used dot operator to access the grade member of the student
cout << "Name: " << student3.name << endl; //used cout to print the name
cout << "Age: " << student3.age << endl; //used cout to print the age
cout << "Grade: " << student3.grade << endl; //used cout to print the grade
}