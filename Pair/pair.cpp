#include<bits/stdc++.h>
using namespace std;
int main(){
    pair<int,int> p = {1,3};
    cout<<p.first<<" "<<p.second<<endl;
    pair<int,pair <int,int>> q = {1,{3,4}};
    cout<<q.first<<" "<<q.second.first<<" "<<q.second.second<<endl;
    pair<int, int> arr[] = {{1,2},{3,4},{5,6}}; //array of datatype pair<int,int>
    cout<<arr[1].second;
    return 0;
}