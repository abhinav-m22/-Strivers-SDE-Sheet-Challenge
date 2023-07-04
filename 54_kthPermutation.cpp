#include<bits/stdc++.h>
using namespace std;

void permutationHelper(string& s, int ind, vector<string>& v){
    if(ind == s.size()){
        v.push_back(s);
        return;
    }

    for(int i = ind; i < s.size(); i++){
        swap(s[i], s[ind]);
        permutationHelper(s, ind+1, v);
        swap(s[i], s[ind]);
    }
}

// Time Complexity: O(N! * N) +O(N! Log N!)
// Space complexity: O(N) 
string kthPermutation(int n, int k) {
    string s;
    vector<string> v;

    for(int i = 1; i <= n; i++){
        s.push_back(i + '0');
    }

    permutationHelper(s, 0, v);

    sort(v.begin(), v.end());

    auto it = v.begin() + (k-1);
    return *it;

}
