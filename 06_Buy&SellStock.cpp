#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int n = prices.size();
    int mini = INT_MAX;
    int maxi = INT_MIN;

    for(int i = 0; i < n; i++){
        mini = min(mini, prices[i]);
        maxi = max(maxi, prices[i] - mini);
    }

    return maxi;
}