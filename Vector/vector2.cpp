#include <iostream>
#include <vector>
using namespace std;

// BAD: Copies the entire vector
void processSlowly(vector<int> v) {
    v[0] = 99; 
}

// GOOD: Passes a reference (remote control) to the original
void processFast(vector<int>& v) {
    v[0] = 99; 
}

// BEST (Read-Only): If you don't need to change it, use const reference
void printVector(const vector<int>& v) {
    cout << v[0]; 
}

int main(){
    vector<int> scores = {10, 20, 30};
    vector<int>* ptr = &scores; // ptr now points to the whole vector

    // To access the size:
    cout << ptr->size(); // Prints 3

    // To access an element, both of these work:
    cout << (*ptr)[0];   // Prints 10
    cout << ptr->at(0);  // Prints 10 (safer, checks if it exists)
    return 0;
}