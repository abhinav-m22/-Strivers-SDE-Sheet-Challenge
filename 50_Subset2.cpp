#include<bits/stdc++.h>
using namespace std;

void f(vector<int>&arr, int ind, vector<int>& v, set<vector<int>>& s){
    int n = arr.size();
    if(ind == n){
        sort(v.begin(), v.end());
        s.insert(v);
        return;
    }
    v.push_back(arr[ind]);
    f(arr, ind+1, v, s);
    v.pop_back();
    f(arr, ind+1, v, s);
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<vector<int>> ans;
    set<vector<int>> s;
    vector<int> v;
    f(arr, 0, v, s);
    for(auto it = s.begin(); it != s.end(); it++){
        ans.push_back(*it);
    }
    return ans;
}