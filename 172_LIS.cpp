#include <bits/stdc++.h>
using namespace std;

// TLE
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> output(n);
    output[0] = 1;

    for(int i = 1; i < n; i++){
        int ans = 0;
        for(int j = i-1; j >= 0; j--){
            if(arr[j] < arr[i]) ans = max(ans, output[j]);
        }
        output[i] = ans + 1;
    }

    int res = 0;
    for(int i = 0; i < n; i++) res = max(res, output[i]);

    return res;
}

// Runtime
int getAns(int arr[], int n,  int ind, int prev_index, vector<vector<int>>& dp){
    if(ind == n) return 0;
    if(dp[ind][prev_index+1] != -1) return dp[ind][prev_index+1];

    int notTake = 0 + getAns(arr, n, ind+1, prev_index, dp);
    
    int take = 0;
    if(prev_index == -1 || arr[ind] > arr[prev_index]){
        take = 1 + getAns(arr, n, ind+1, ind, dp);
    }

    return dp[ind][prev_index+1] = max(take, notTake);
}
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    return getAns(arr, n, 0, -1, dp);
}

// Optimal
int longestIncreasingSubsequence(int arr[], int n)
{

  vector<int>temp;
  temp.push_back(arr[0]);

  for(int i=1;i<n;i++){
        if(arr[i]>temp.back()){
            temp.push_back(arr[i]);
        }else{
            int ind=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
            temp[ind]=arr[i];
        }
  }
    
  return temp.size();

}
