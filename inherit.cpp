#include <iostream>
using namespace std;
class person{
    public:
    string name;

   void showname();
    person(string n);
};
class student: public person{
    public:
    string grade;
    void showgrade();
    student(string n, string g);
};
person::person(string n){
    name = n;
}
void person::showname(){
    cout << "Name: " << name << endl;
}
student::student(string n, string g): person(n){
    grade = g;
}
void student::showgrade(){
    cout << "Grade: " << grade << endl;
}

int main(){
    student s1("Alice", "A");
    s1.showname();
    s1.showgrade();
    return 0;
}