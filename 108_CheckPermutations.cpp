#include <bits/stdc++.h>
using namespace std;

// Solution 1
bool areAnagram(string &s, string &t)
{
    if (s.size() != t.size())
    {
        return false;
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != t[i])
        {
            return false;
        }
    }
    return true;
}

// Solution 2
bool areAnagram(string &s, string &t)
{
    if (s.length() != t.length())
        return false;
    int n = s.length();
    int counts[26] = {0};
    for (int i = 0; i < n; i++)
    {
        counts[s[i] - 'a']++;
        counts[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++)
        if (counts[i])
            return false;
    return true;
}