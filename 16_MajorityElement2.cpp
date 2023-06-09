#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    vector<int> v;
    int n = arr.size();
    unordered_map<int, int> mp;
	for(int i = 0; i < n; i++){
		mp[arr[i]]++;
	}
	for(auto it : mp){
		if(it.second > n/3) v.push_back(it.first);
	}
	return v;

}