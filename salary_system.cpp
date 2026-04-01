#include <iostream>
using namespace std;
class employee {
    private:
        string name;
        int id;
        double salary;
    public:
        employee(string n, int i, double s);
        void setemployee(string n, int i, double s);
        void getemployee();
};
class programmer: public employee {
    private:
      int bonus;
    public:
        programmer(string n, int i, double s, int b);
        void setprogrammer(string n, int i, double s, int b);
        void getprogrammer();
};

employee::employee(string n, int i, double s) {
    name = n;
    id = i;
    salary = s;
}
void employee::setemployee(string n, int i, double s) {
    name = n;
    id = i;
    salary = s;
}
void employee::getemployee() {
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "Salary: " << salary << endl;
}
programmer::programmer(string n, int i, double s, int b): employee(n
    , i, s) {
    bonus = b;
}
void programmer::setprogrammer(string n, int i, double s, int b) {
    setemployee(n, i, s);
    bonus = b;
}
void programmer::getprogrammer() {
    getemployee();
    cout << "Bonus: " << bonus << endl;
}

int main() {
    employee e1("John", 1001, 60000);
    e1.getemployee();
    programmer p1("Alice", 101, 50000, 5000);
    p1.getprogrammer();
    return 0;
}