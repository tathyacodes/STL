#include<bits/stdc++.h>
using namespace std;

int main() {
    map < int, int > mp;
    for (int i = 1; i <= 5; i++) {
        mp.insert({i , i * 10});
    }
    cout << "Elements present in the map: " << endl;
    cout << "Key\tElement" << endl;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << "\t" << it->second << endl;
    }
    
    int n = 2;
    if (mp.find(2) != mp.end()) //.find(x) returns an iterator pointing to the key-value pair where the key is x, else returns .end()
        cout << mp.find(2)->first << " is present in map with its value = " << mp.find(2)->second <<endl;
    
    mp.erase(mp.begin());
    cout << "Elements after deleting the first element: " << endl;
    cout << "Key\tElement" << endl;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        cout << it -> first << "\t" << it -> second << endl;
    }
    
    cout << "The size of the map is: " << mp.size() << endl;
    
    if (mp.empty() == false)
        cout << "The map is not empty " << endl;
    else
        cout << "The map is empty" << endl;
    mp.clear();
    cout << "Size of the map after clearing all the elements: " << mp.size();
}
// A map stores its keys in a balanced binary search tree.
// An unordered map stores its keys in a hash table.
// Map:
// access mp[i] -> O(logn)
// mp.insert({key,value}) -> O(logn)
// mp.emplace_hint(iterator,key,value) -> O(logn) or O(1) amortized if hint is close enough
// mp.find(key) -> O(logn)
// mp.count(key) -> O(logn)
// mp.erase(key) -> O(logn)
// mp.erase(iterator) -> O(1) amortized
// mp.begin() / mp.end() -> O(1)
// mp.lower_bound(key) / mp.upper_bound(key) -> O(logn)
// mp.size() / mp.empty() / mp.clear() / mp.swap(mp2) -> O(1)

// Unordered Map:
// insert       O(1) average
// find         O(1) average
// erase(key)   O(1) average
// count        O(1) average
// [key]        O(1) average
// begin        O(1)
// end          O(1)
// size         O(1)
// empty        O(1)
// https://chatgpt.com/share/6ab76999-981c-83e8-9e05-b07ff31bfc3a