#include<bits/stdc++.h>
using namespace std;

void f(vector<int>& arr, vector<int>& v, vector<vector<int>>& ans, int ind){
    ans.push_back(v);
    for(int i = ind; i < arr.size(); i++){
        v.push_back(arr[i]);
        f(arr, v, ans, i+1);
        v.pop_back();
    }
}

vector<vector<int>> pwset(vector<int> arr)
{
    vector<int> v;
    vector<vector<int>> ans;
    f(arr, v, ans, 0);
    return ans;
}