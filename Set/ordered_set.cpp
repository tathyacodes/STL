#include<bits/stdc++.h>
using namespace std;
int main(){
    set<int> s;
    s.emplace(2);
    s.emplace(1);
    s.emplace(2); // does not store another 2, set stores unique elements
    s.emplace(5);
    s.insert(3); // {1,2,3,5} can be a representation, although set internally stores as a tree, not as a linear structure

    cout<<s.count(1)<<endl;
    cout<<s.count(4)<<endl;

    auto it = s.find(5);
    s.emplace_hint(it,4); //emplaces 4 with hint of iterator to expected position of 4

    // emplace_hint() is basically emplace() + a hint about where to insert the element.
    // It is commonly used with set, map, multiset, and multimap.
    // If you already know the correct position, the hint can make insertion faster.
    // A good/accurate hint can make insertion faster; a bad hint doesn't make the insertion incorrect.
    // It returns an iterator to the inserted element (or to the already-existing equivalent element for a set).
    // The hint doesn't force the insertion there.
    // s.emplace_hint(s.end(), 0);
    // The set will still put 0 in its correct sorted position. The hint is just information that can potentially improve performance.

    auto it2 = s.find(3);
    cout << *it2 << endl;

    auto it3 = s.find(6);
    if (!s.empty()) cout << *prev(s.end()) << endl; 
    return 0;
}
// https://chatgpt.com/share/6ab68ea4-a9bc-83e8-b2b5-0bab9ae82a1b