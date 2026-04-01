#include <iostream>
// Animal Sound System using Inheritance and Polymorphism
using namespace std;
class animal{
    public:
   virtual void sound();
};
void animal::sound(){
    cout << "Animal makes a sound" << endl;
}
class dog: public animal{
    public:
    void sound() override {
        cout << "Dog barks" << endl;
    }
};
class cat: public animal{
    public:
    void sound() override {
        cout << "Cat meows" << endl;
    }
};

int main(){
    animal* a1 = new dog();
    animal* a2 = new cat();
    a1->sound();
    a2->sound();
    delete a1;
    delete a2;
    return 0;
}
