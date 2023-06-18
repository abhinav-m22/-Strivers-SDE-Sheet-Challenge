#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach: Time Complexity: O(n^3), Space Complexity: O(3*k)
vector<vector<int>> findTriplets(vector<int> arr, int n, int k)
{
    vector<vector<int>> ans;
    vector<int> temp;
    int i, j, k;
    for (i = 0; i < arr.size() - 2; i++)
    {
        for (j = i + 1; j < arr.size() - 1; j++)
        {
            for (k = j + 1; k < arr.size(); k++)
            {
                temp.clear();
                if (arr[i] + arr[j] + arr[k] == 0)
                {
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[k]);
                }
                if (temp.size() != 0)
                    ans.push_back(temp);
            }
        }
    }

    return ans;
}

// Time Complexity: O(n^2 * log(n)), Space Complexity: O(n)
vector<vector<int>> findTriplets(vector<int> arr, int n, int k)
{
    set<vector<int>> s;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 2; i++)
    {
        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            int sum = arr[i] + arr[left] + arr[right];
            if (sum == k)
            {
                vector<int> v = {arr[i], arr[left], arr[right]};
                sort(v.begin(), v.end());
                s.insert(v);
                left++;
                right--;
            }
            else if (sum > k)
            {
                right--;
            }
            else
                left++;
        }
    }

    vector<vector<int>> ans(s.begin(), s.end());
    return ans;
}