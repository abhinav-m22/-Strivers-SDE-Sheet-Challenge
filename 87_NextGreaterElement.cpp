#include <bits/stdc++.h> 
using namespace std;

vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    vector<int> v(n, -1);
    stack<int> st;

    for(int i = 0; i < n; i++){
        while(!st.empty() && arr[i] > arr[st.top()]){
            v[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return v;
}