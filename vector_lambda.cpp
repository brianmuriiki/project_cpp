#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct Student {
    string name;
    int age;
    int score;
};
//student management system using vector and lambda function
int main() {
   vector<Student> students; //used vector to store student records
   int n;
    cout << "Enter number of students: "<< endl;
    cin >>n;
    for(int i = 0; i < n ; i++){
        Student pupils;
        cout << "Enter name,score and age of student " << i + 1 << ": ";
        cin >> pupils.name >>pupils.score>> pupils.age; //used cin to input student details
        students.push_back(pupils); //used push_back to add student to the vector
    }
    //grading students using lambda function

    auto grade = [](int score) { 
        if (score >= 90) return 'A';
        else if (score >= 80) return 'B';
        else if (score >= 70) return 'C';
        else if (score >= 60) return 'D';
        else return 'F';
    };
 
    //sorting students by score using lambda function
    sort(students.begin(), students.end(), []( Student a,  Student b ) {
        
        return a.score > b.score; //sort in descending order
    });

    //printing student report using lambda function
    auto printReport = [&grade](const vector<Student>& students) {
        cout << "\nStudent Report:\n";
        for (auto& stud : students) {
            cout << "Name: " << stud.name
                 << " Score: " << stud.score
                 << " Grade: " << grade(stud.score)
                 << " Age: " << stud.age << endl;ffff
        }
    };

    printReport(students); //called the lambda function to print the student report
    return 0;
}