#include <iostream>
//library management system 
using namespace std;
class libraryitem{
    protected:
        string title;
        string author;
        string id;
        int publicationdate;
    public:
       libraryitem(string t, string a, string i, int p) {
    title = t;
    author = a;
    id = i;
    if (p > 0) {
        publicationdate = p;
    } else {
        publicationdate = 0; // Default value for invalid publication date
    }
}
     virtual ~libraryitem() {}
       virtual void setitemdetails(string t, string a, string i, int p)
{
    title = t;
    author = a;
    id = i;
    publicationdate = p;
}
         virtual void getitemdetails() {
     cout << "Title: " << title << endl;
     cout << "Author: " << author << endl;
     cout << "ID: " << id << endl;
     cout << "Publication Date: " << publicationdate << endl;
}
};

class book: public libraryitem {
    protected:
    int numpages;
    public:
   book(string t, string a, string i, int p, int n): libraryitem(t, a, i, p) {
    numpages = n;
}
    void setbookdetails(string t, string a, string i, int p, int n) {
    setitemdetails(t, a, i, p);
    numpages = n;
}
   void getitemdetails() override {
    libraryitem::getitemdetails();
    cout << "Number of Pages: " << numpages << endl;
}
};

class magazine: public libraryitem {
    protected:
    int issue_number;
    int month_of_publication;
    public:
   magazine(string t, string a, string i, int p, int issue, int month): libraryitem(t, a, i, p) {
    issue_number = issue;
    month_of_publication = month;
}
    void setmagazinedetails(string t, string a, string i, int p, int issue, int month) {
    setitemdetails(t, a, i, p);
    issue_number = issue;
    month_of_publication = month;
}
   void getitemdetails() override{
    libraryitem::getitemdetails();
    cout << "Issue Number: " << issue_number << endl;
    cout << "Month of Publication: " << month_of_publication << endl;
}
};

int main() {
    book* b1 = new book("The Great Gatsby", "F. Scott Fitzgerald", "B001", 1925, 180);
    magazine* m1 = new magazine("National Geographic", "Various", "M001", 0000, 0, 0);
    b1->getitemdetails();
    m1->getitemdetails();
    return 0;
}