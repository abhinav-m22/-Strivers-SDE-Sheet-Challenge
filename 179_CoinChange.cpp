#include <bits/stdc++.h>
using namespace std;

long f(int* arr, int ind, int t, vector<vector<long>>& dp){
    if(ind == 0){
        return (t%arr[0] == 0);
    }

    if(dp[ind][t] != -1) return dp[ind][t];

    long notTake = f(arr, ind-1, t, dp);
    long take = 0;

    if(arr[ind] <= t){
        take = f(arr, ind, t-arr[ind], dp);
    }

    return dp[ind][t] = (take+notTake);
}

long countWaysToMakeChange(int *arr, int n, int t)
{
    vector<vector<long>> dp(n, vector<long>(t+1, -1));
    return f(arr, n-1, t, dp);
}