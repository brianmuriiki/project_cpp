#include <iostream>
using namespace std;

class student {
    private:
        string name;
        int marks;
    public:
        student(string n, int m);//constructor
        
        friend void displaystudent(student s);//friend function declaration
    };
     student::student(string n, int m) {
        name = n;
        marks = m;
    }
    void displaystudent(student s) {
        cout << "Name: " << s.name << endl;
        cout << "Marks: " << s.marks << endl;
    }

    int main() {
        student s1("Alice", 85);
        displaystudent(s1);
        return 0;
    }
