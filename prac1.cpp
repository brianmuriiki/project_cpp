#include <iostream>
using namespace std;
class student {
    private:
        string name;
        int marks;
        int age;
        string course;
    public:
    //constructor
        student(string n, int m, int a, string c);
        void setrecord(string n, int m, int a, string c);
        void getrecord();
};
student::student(string n, int m, int a, string c) {
    name = n;
    marks = m;
    age = a;
    course = c;
}
void student::setrecord(string n, int m, int a, string c) {
    name = n;
    marks = m;
    age = a;
    course = c;
}
void student::getrecord() {
    cout << "Name: " << name << endl;
    cout << "Marks: " << marks << endl;
    cout << "Age: " << age << endl;
    cout << "Course: " << course << endl;
}

int main(){
    student s1("Alice", 85, 20, "Computer Science");
    student s2("Bob", 90, 22, "Mathematics");
    s1.getrecord();
    s2.getrecord();
    return 0;
}