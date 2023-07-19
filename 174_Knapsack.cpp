
#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int> &weights, vector<int> &values, int ind, int w, vector<vector<int>>& dp){
	if(ind == 0){
		if(weights[0] <= w) return values[0];
		else return 0;
	}

	if(dp[ind][w] != -1) return dp[ind][w];

	int notTake = 0 + knapsack(weights, values, ind-1, w, dp);
	int take = 0;

	if(weights[ind] <= w){
		take = values[ind] + knapsack(weights, values, ind-1, w-weights[ind], dp);
	}

	return dp[ind][w] = max(take, notTake);
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<vector<int>> dp(n, vector<int>(w+1, -1));
	return knapsack(weights, values, n-1, w, dp);
}