#include <bits/stdc++.h> 
using namespace std;

// Brute Force - O(n^2)
int uniqueSubstrings(string s){ 

    int n = s.size();
    
    if(n == 0) return 0;

    int ans = INT_MIN;

    for(int i = 0; i < n; i++){
        unordered_set<int> st;
        for(int j = i; j < n; j++){
            if(st.find(s[j]) != st.end()){
                ans = max(ans, j-i);
                break;
            }
            st.insert(s[j]);
        }
    }
    return ans;
}

// Optimal - 1 -> O(2*N)
int uniqueSubstrings(string s){
    if(s.size() == 0) return 0;

    int ans = INT_MIN;

    unordered_set<int> st;
    int l = 0;
    for(int r = 0; r < s.size(); r++){
        if(st.find(s[r]) != st.end()){
            while(l < r && st.find(s[r]) != st.end()){
                st.erase(s[l]);
                l++;
            }
        }
        st.insert(s[r]);
        ans = max(ans, r-l+1);
    }
    return ans;
}