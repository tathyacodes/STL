#include<bits/stdc++.h>
using namespace std;
void printqueue(priority_queue<int> q1)
{
    priority_queue<int> q2=q1;
    while(!q2.empty())  //Iterate while the queue in not empty
    {
        cout<<q2.top()<<"\n";
        q2.pop();
    }
}
int main()
{
    priority_queue<int> pq; //max heap
    pq.push(5); //{5}
    pq.push(2); //{5,2}
    pq.push(8); //{8,5,2}
    pq.emplace(10); //{10,8,5,2} can be a representation, although priority_queue internally stores as a tree, not as a linear structure
    
    cout<<"The elements of the queue are:"<<endl;
    printqueue(pq);

    priority_queue<int, vector<int>, greater<int>> pq2; //min heap
    pq2.push(5); //{5}
    pq2.push(2); //{2,5}
    pq2.push(8); //{2,5,8}
    pq2.emplace(10); //{2,5,8,10} can be a representation, although priority_queue internally stores as a tree, not as a linear structure
    cout<<pq2.top();
}
// push, pop = O(logn)
// top = O(1)