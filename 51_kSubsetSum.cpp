#include <bits/stdc++.h>
using namespace std;

void findSubsetsThatSumToK(int ind, vector<vector<int>> &ans, vector<int> &v, vector<int> &arr, int k)
{
    int n = arr.size();
    if (ind == n)
    {
        if (k == 0)
            ans.push_back(v);
        return;
    }

    v.push_back(arr[ind]);
    findSubsetsThatSumToK(ind + 1, ans, v, arr, k - arr[ind]);
    v.pop_back();

    findSubsetsThatSumToK(ind + 1, ans, v, arr, k);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> ans;
    vector<int> v;
    findSubsetsThatSumToK(0, ans, v, arr, k);
    return ans;
}