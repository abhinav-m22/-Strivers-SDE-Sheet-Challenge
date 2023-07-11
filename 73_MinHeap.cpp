#include <bits/stdc++.h> 
using namespace std;

// Using Heap
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int> v;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto it: kArrays){
        for(auto i: it) pq.push(i);
    }

    while(!pq.empty()){
        v.push_back(pq.top());
        pq.pop();
    }

    return v;
}

// Brute Force - simple sorting
vector<int> solve(vector<int> array, vector<int> ans){
    for(int i=0; i<array.size(); i++){
        ans.push_back(array[i]);
    }
    return ans;
}

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int> ans;
    int n=kArrays.size();
    for(int i=0; i<k; i++){
        ans=solve(kArrays[i], ans);
        }
    sort(ans.begin(), ans.end());
    return ans;
}