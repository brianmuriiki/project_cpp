#include <iostream>
using namespace std;
class book{
    public:
    string title;
    string author;
    book(string t, string a);
    void setbook(string t, string a);
    void showbook();
};
book::book(string t, string a){//constructor
    title = t;
    author = a;
}
//void book::setbook(string t, string a){
  //  title = t;
    //author = a;
//}
void book::showbook(){
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
}
int main(){
    book b1("The Catcher in the Rye", "J.D. Salinger");
    b1.showbook();
    return 0;
}
