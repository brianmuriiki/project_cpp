#include <iostream>
using namespace std;
class vehicle {
    protected:
        string name;
        public:
        vehicle(string n){
            name = n;
        }
        void setname(string n) {
            name = n;
        }
       virtual void showname() {
            cout << "Vehicle Name: " << name << endl;
        }
};
class car: public vehicle {
    public:
        car(string n): vehicle(n) {
            
        }
        void setname(string n) {
         
        }

        void showname() override {
            cout << "Car Name: " << name << endl;
        }

};
class bike: public vehicle {
    public:
        bike(string n): vehicle(n) {
        
        }
        void setname(string n) {
           
        }
        void showname() override {
            cout << "Bike Name: " << name << endl;
        }
};
class truck: public vehicle {
    public:
        truck(string n): vehicle(n) {
            
        }
        void setname(string n) {
            
        }
        void showname() override {
            cout << "Truck Name: " << name << endl;
        }
};

int main(){
    vehicle* v1 = new car("Toyota");
    vehicle* v2 = new bike("Yamaha");
    vehicle* v3 = new truck("Ford");
    v1->showname();
    v2->showname();
    v3->showname();
    delete v1;
    delete v2;
    delete v3;
    return 0;
}