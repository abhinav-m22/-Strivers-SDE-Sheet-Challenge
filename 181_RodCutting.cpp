int solve(int i, int W, vector<int> &price, vector<vector<int>> &dp) {
  if (i == 0) {
    return W * price[0];
  }
  if (dp[i][W] != -1)
    return dp[i][W];

  int take = INT_MIN;
  if (i + 1 <= W)
    take = price[i] + solve(i, W - (i + 1), price, dp);

  int notake = solve(i - 1, W, price, dp);

  return dp[i][W] = max(take, notake);
}

int cutRod(vector<int> &price, int n) {
  vector<vector<int>> dp(n, vector<int>(n + 1, -1));
  return solve(n - 1, n, price, dp);
}