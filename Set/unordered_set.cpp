// What is an unordered set?
// An unordered set in STL is a container that stores unique elements in no particular order.
// Every operation on an unordered set takes O(1) complexity in the average case and takes O(n) in the worst case.

// Functions in unordered set:
// insert() - to insert an element in the unordered set.
// begin() - return an iterator pointing to the first element in the unordered set.
// end() - returns an iterator to the theoretical element after the last element.
// count() - it returns 1 if the element is present in the container otherwise 0.
// clear() - deletes all the elements in unordered set.
// find() - to search an element in the unordered set.
// size() - returns the size of the unordered set.

// Other functions:
// cbegin() – it refers to the first element of the unordered set. c means const, read-only iterators.
// cend() – it refers to the theoretical element after the last element of the unordered set.
// bucket_size() - gives the total number of elements present in a specific bucket in an unordered set.
// emplace() - to insert an element in the unordered set.
// max_size() - the maximum elements an unordered_set can hold.
// max_bucket_count() - to check the maximum number of buckets an unordered set can hold.

#include<bits/stdc++.h>
using namespace std;

int main() {
    // Declare an unordered_set of integers
    unordered_set<int> s;

    // Insert elements from 1 to 10 into the unordered_set
    for (int i = 1; i <= 10; i++) {
        s.insert(i); // insert() adds a new element to the set
    }

    cout << *s.begin()<<endl;
    // cout << *s.end()<<endl;

    // Display all elements present in the unordered_set
    cout << "Elements present in the unordered set: ";
    for (auto t = s.begin(); t != s.end(); t++) {
        cout << *t << " "; // Dereference iterator to access the element
    }
    cout << endl;

    int n = 12;
    // Check if element 2 exists in the set using find()
    if (s.find(n) != s.end()) // find() returns an iterator to element if found, else s.end()
        cout << n << " is present in unordered set" << endl;

    // Erase the first element from the set using iterator
    s.erase(s.begin()); // erase() removes element at given iterator position

    // Display elements after deletion
    cout << "Elements after deleting the first element: ";
    for (auto it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // Display size of the unordered set
    cout << "The size of the unordered set is: " << s.size() << endl;

    // Check if the unordered set is empty
    if (s.empty() == false) // empty() returns true if set has no elements
        cout << "The unordered set is not empty " << endl;
    else
        cout << "The unordered set is empty" << endl;

    // Clear all elements from the unordered set
    s.clear(); // clear() removes all elements

    // Display size after clearing
    cout << "Size of the unordered set after clearing all the elements: " << s.size();
    
}