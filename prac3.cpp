#include <iostream>
#include <vector>
using namespace std;

struct students {
    string name;
    int score;
    char grade;
    int rank;
    int index;
};

char grading(int score) {
    if (score >= 90) return 'A';
    else if (score >= 80) return 'B';
    else if (score >= 70) return 'C';
    else if (score >= 60) return 'D';
    else return 'F';
}

void calculateRank(vector<students>& s, int n) {
    for (int i = 0; i < n; i++) {
        s[i].rank = 1;
        for (int j = 0; j < n; j++) {
            if (s[i].score < s[j].score) {
                s[i].rank++;
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    vector<students> s(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter name and score of student " << i + 1 << ": ";
        cin >> s[i].name >> s[i].score;
        s[i].index = i;
        s[i].grade = grading(s[i].score);
    }

    calculateRank(s, n);

    cout << "\nStudent Report:\n";
    for (int i = 0; i < n; i++) {
        cout << "Name: " << s[i].name
             << " Score: " << s[i].score
             << " Grade: " << s[i].grade
             << " Rank: " << s[i].rank << endl;
    }

    return 0;
}