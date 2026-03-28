#include <iostream>
using namespace std;
int main() {
    int numbers[] = {1, 2, 3, 4, 5};//used omit array size
    for (int num : numbers) { //used for-each loop to iterate through the array
        cout << num << " ";
    }
}