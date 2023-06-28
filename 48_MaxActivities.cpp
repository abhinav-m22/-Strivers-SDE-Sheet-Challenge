#include <bits/stdc++.h>
using namespace std;

int maximumActivities(vector<int> &start, vector<int> &finish) {
    
    int n = start.size();
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++){
        v.push_back({finish[i], start[i]});
    }

    sort(v.begin(), v.end());
    int e = -1;
    int ans = 0;

    for(auto it : v){
        if(it.second > e-1){
            ans++;
            e = it.first;
        }
    }
    return ans;
}