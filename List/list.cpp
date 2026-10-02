#include<bits/stdc++.h>
using namespace std;

int main() {
    list<int> ls;
    ls.push_back(2);
    ls.emplace_back(4);
    ls.push_front(3);
}

// list internally is doubly ll, while vector is dynamic array, and deque is segmented array
// list provides front operations in addition to those of vectors.
// .push_front() in list costs less time than .insert(.begin(), ) in vector
// https://chatgpt.com/share/6ab5577c-0058-83ee-af95-aeb5c34c5235 difference between deque and list