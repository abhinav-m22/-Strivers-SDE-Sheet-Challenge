#include<bits/stdc++.h>
using namespace std;

void subsetSumHelper(int ind, int n, vector<int>&num, vector<int>&v, int sum){
    if(ind == n){
        v.push_back(sum);
        return;
    }

    subsetSumHelper(ind+1, n, num, v, sum+num[ind]);
    subsetSumHelper(ind+1, n, num, v, sum);
}

vector<int> subsetSum(vector<int> &num){
    vector<int> v;
    int n = num.size();
    subsetSumHelper(0, n, num, v, 0);
    sort(v.begin(), v.end());
    return v;
}