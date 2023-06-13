#include <bits/stdc++.h>
using namespace std;

// Brute Force - O(n^4)
string fourSum(vector<int> arr, int target, int n)
{
    set<vector<int>> s;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    long long sum = arr[i] + arr[j] + arr[k] + arr[l];

                    if (sum == target)
                    {
                        // vector<int> v = {arr[i], arr[j], arr[k], arr[l]};
                        // sort(v.begin(), v.end());
                        // s.insert(v);
                        return "Yes";
                    }
                }
            }
        }
    }
    return "No";
}

// Better-1 -> O(N^3 * log(m))

string fourSum(vector<int> arr, int target, int n)
{
    set<vector<int>> s;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            set<long long> st;
            for (int k = j + 1; k < n; k++)
            {
                long long sum = arr[i] + arr[j] + arr[k];
                long long fourth = target - sum;

                if (st.find(fourth) != st.end())
                {
                    vector<int> v = {arr[i], arr[j], arr[k], (int)fourth};
                    sort(v.begin(), v.end());
                    s.insert(v);
                }
                st.insert(arr[k]);
            }
        }
    }

    if (s.size())
        return "Yes";
    return "No";
}

// Better-2 -> O(n^3)
string fourSum(vector<int> arr, int target, int n)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && arr[j] == arr[j - 1])
                continue;

            int k = j + 1;
            int l = n - 1;

            while (k < l)
            {
                long long sum = arr[i] + arr[j] + arr[k] + arr[l];
                if (sum == target)
                {
                    vector<int> v = {arr[i], arr[j], arr[k], arr[l]};
                    ans.push_back(v);
                    k++;
                    l--;

                    while (k < l && arr[k] == arr[k - 1])
                        k++;
                    while (k < l && arr[l] == arr[l + 1])
                        l--;
                }
                else if (sum < target)
                    k++;
                else
                    l--;
            }
        }
        if (ans.size())
            return "Yes";
        return "No";
    }
}

// Optimal-1 -> O(n^3)

#define ll long long
string fourSum(vector<int> arr, int target, int n)
{
    sort(arr.begin(), arr.end());

    vector<vector<int>> v;
    set<vector<int>> s;

    for (ll i = 0; i < n; i++)
    {
        for (ll j = i + 1; j < n; j++)
        {
            ll start = j + 1;
            ll end = n - 1;
            while (start < end)
            {
                ll sum = (ll)arr[i] + (ll)arr[j] + (ll)arr[start] + (ll)arr[end];
                if (sum == target)
                    s.insert({arr[i], arr[j], arr[start], arr[end]}), start++, end--;
                else if (sum > target)
                    end--;
                else
                    start++;
            }
        }
    }
    if (s.size())
        return "Yes";
    return "No";
}

// Optimal-2 -> O(n^2 * log(n))

string fourSum(vector<int> arr, int target, int n)
{
    map<long long, pair<int, int>> mp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            long long sum = arr[i] + arr[j];
            if (mp.find(target - sum) != mp.end())
            {
                if (mp[target - sum].first != i && mp[target - sum].second != i && mp[target - sum].first != j && mp[target - sum].second != j)
                {
                    return "Yes";
                }
            }
            mp[sum] = {i, j};
        }
    }
    return "No";
}