#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) {
  vector<vector<long long int>> ans;
  ans.push_back({1});
  for (int i = 1; i < n; i++) {
    vector<long long int> v;
    v.push_back(1);
    for (int j = 0; j < ans[i - 1].size() - 1; j++) {
      v.push_back(ans[i - 1][j] + ans[i - 1][j + 1]);
    }
    v.push_back(1);
    ans.push_back(v);
  }
  return ans;
}
