#include <bits/stdc++.h> 
using namespace std;

int maxIncreasingDumbbellsSum(vector<int> &arr, int n)
{
	vector<int> dp(arr.begin(), arr.end());
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			if(arr[j] < arr[i]){
				dp[i] = max(dp[i], dp[j]+arr[i]);
			}
		}
	}

	return *max_element(dp.begin(), dp.end());
}