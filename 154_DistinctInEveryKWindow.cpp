#include <bits/stdc++.h>
using namespace std;
 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    vector<int> ans;
    int n = arr.size();
    unordered_map<int, int> mp;
    for(int i = 0; i < k; i++) mp[arr[i]]++;
    for(int i = 0; i < n-k; i++){
        ans.push_back(mp.size());
        if(mp[arr[i]]-- == 1) mp.erase(arr[i]);
        mp[arr[i+k]]++;
    }
	ans.push_back(mp.size());
    return ans;
}
