#include<bits/stdc++.h>
using namespace std;
int main(){

    stack<int> st;
    st.push(1);
    st.emplace(2);
    st.push(3);
    st.pop();

    stack<int> st2;
    st2.push(3);
    st2.emplace(4);
    st2.push(5);
    st2.pop();

    cout<<st.top()<<endl;
    cout<<st.size()<<endl;
    cout<<st.empty()<<endl;
    st.swap(st2);
    cout<<st.top();
    
    return 0;
}
//indexing is not allowed in stack, st[i] is not valid.