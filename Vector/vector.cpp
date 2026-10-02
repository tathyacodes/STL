#include<bits/stdc++.h>
using namespace std;

int main() {

vector <pair<int,int>> vec;

// pair <int,int> temp = {1,2};
// vec.push_back(temp);

vec.push_back({1,2}); //adds an already created object {1,2}
vec.emplace_back(3,4); //construct the object directly inside the container

cout << vec.front().first << " " << vec.front().second << endl;
cout << vec.back().first << " " << vec.back().second << endl;

vector <int> vec2(5,20); //{20,20,20,20,20}
//vector <int> vec3(vec2); creates a copy of vec2

vector <int> v;

for (int i = 0; i < 8; i++) {
    v.push_back(i); //inserting elements in the vector
}
cout<<v.max_size()<<endl;
cout<<v.capacity()<<endl; //try again with changing to i<9 in for loop

// vector<int>::iterator it = v.begin(); is the formal way to 
// auto it = v.begin();

cout << "the elements in the vector: ";
for (auto it = v.begin(); it != v.end(); it++) cout << *it << " ";
cout<<endl;
for (auto it : v) cout << it << " "; //here 'it' is an iterator of elements (int datatype) and not of their addresses, so no need to dereference
cout<<endl;
cout << "\nThe front element of the vector: " << v.front();  //The front element of the vector
cout << "\nThe last element of the vector: " << v.back(); //The last element of the vector
cout << "\nThe size of the vector: " << v.size();  //The size of the vector
cout << "\nDeleting element from the end: " << v[v.size() - 1];  //Deleting element from the end
v.pop_back();

cout << "\nPrinting the vector after removing the last element:" << endl;
for (int i = 0; i < v.size(); i++)
  cout << v[i] << " ";

cout << "\nInserting 5 at the beginning:" << endl;
v.insert(v.begin(),5);
//v={40,50,60}
//v.insert(v.begin()+1,2,30);  {40,30,30,50,60}

//v2={20,20};
//v.insert(v.begin(),v2.begin(),v2.end());  {20,20,40,30,30,50,60}  insertion of one vector into other

cout << "The first element is: " << v[0] << endl;

cout << "Erasing the first element" << endl;

v.erase(v.begin());  //Erasing the element
//v.erase(v.begin()+2,v.begin()+5); erases the elements v[2], v[3], v[4]
//v.erase(a,b); erases the elements [a,b) excluding the element at position b

cout << "Now the first element is: " << v[0] << endl;

if (v.empty())
    cout << "\nvector is empty";  //If empty then print empty else print not empty
else
    cout << "\nvector is not empty" << endl;  //vector is not empty

cout<<*v.cbegin()<<endl;
cout<<*v.cend()<<endl;

v.clear();
cout << "Size of the vector after clearing the vector: " << v.size();

//v1={1,2};
//v2={3,4};
//v1.swap(v2);  v1={3,4}  v2={1,2}
}