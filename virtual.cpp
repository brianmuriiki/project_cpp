#include <iostream>
using namespace std;
class shape {
    public:
        virtual void draw() {
            cout << "Drawing a shape" << endl;
        }
        virtual ~shape() {}
};
class circle: public shape {
    public:
        void draw() override {
            cout << "Drawing a circle" << endl;
        }
};
class square: public shape {
    public:
        void draw() override {
            cout << "Drawing a square" << endl;
        }
};
class triangle: public shape {
    public:
        void draw() override {
            cout << "Drawing a triangle" << endl;
        }
};

int main() {
    shape* s1 = new circle();
    shape* s2 = new square();
    shape* s3 = new triangle();
    s1->draw();
    s2->draw();
    s3->draw();
    return 0;
}