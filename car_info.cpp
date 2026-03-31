#include <iostream>
using namespace std;
class car{
    private:
    string brand;
    string model;
    int year;
    public:
   
    car(string b, string m, int y);
    void setcar(string b, string m, int y);
    void getcar();
};
car::car(string b, string m, int y) {
    brand = b;
    model = m;
    year = y;
}
void car::setcar(string b, string m, int y) {
    brand = b;
    model = m;
    year = y;
}
void car::getcar() {
    cout << "Brand: " << brand << endl;
    cout << "Model: " << model << endl;
    cout << "Year: " << year << endl;
}

int main() {
    car c1("Toyota", "Camry", 2020);
   // c1.setcar("Toyota", "Camry", 2020);
    c1.getcar();
    return 0;
}
