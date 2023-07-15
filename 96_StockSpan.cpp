#include <bits/stdc++.h> 
using namespace std;

vector<int> findSpans(vector<int> &price) {
    vector<int> ans;
    stack<int> st;
    st.push(-1);
    int n = price.size();

    for(int i = 0; i < n; i++){
        while(st.top() != -1 && price[st.top()] <= price[i]) st.pop();

        if(st.top() == -1) ans.push_back(i+1);
        else ans.push_back(i-st.top());

        st.push(i);
    }
    return ans;
}