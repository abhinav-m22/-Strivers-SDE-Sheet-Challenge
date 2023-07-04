#include<bits/stdc++.h>
using namespace std;

void permute(int index, vector<string>& v, string& s){
    if(index == s.size()){
        v.push_back(s);
        return;
    }

    for(int i = index; i < s.size(); i++){
        swap(s[i], s[index]);
        permute(index+1, v, s);
        swap(s[i], s[index]);
    }
}

// Time Complexity: O(N! X N)
// Space Complexity: O(1)

vector<string> findPermutations(string &s) {
    vector<string> v;
    permute(0, v, s);
    return v;
}