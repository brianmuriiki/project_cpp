#include <iostream>
using namespace std;
int main() {
    int ages[8] = {20, 25, 30, 35, 40, 45, 50, 55}; //used an array
    float avg, sum = 0;
    int length = sizeof(ages) / sizeof(ages[0]); //used sizeof to get the length of the array 
    //looping using for-each loop to calculate the sum of ages
    for(int age : ages){
        sum += age; //used for-each loop to calculate the sum of ages
    }
    avg = sum / length; //used the length of the array to calculate the average
  
    int lowest = ages[0]; //used the first element of the array to initialize the lowest age
    int highest = ages[0]; //used the first element of the array to initialize the
    //loop
for(int i : ages){
    if(i < lowest){ //used if statement to find the lowest age
        lowest = i; //used if statement to update the lowest age
    }
    else if(i > highest){ //used if statement to find the highest age
        highest = i; //used if statement to update the highest age
    }
    else{
        continue; //used else statement to continue the loop if the age is not the lowest or highest
    }
}

      cout << "The sum of ages is: " << sum << endl; //used cout to print the sum of ages
    cout << "The average age is: " << avg << endl; //used cout to
    //print the average age
    cout << "The lowest age is: " << lowest << endl; //used cout to print the lowest age
    cout << "The highest age is: " << highest << endl; //used cout to
    return 0;
}
