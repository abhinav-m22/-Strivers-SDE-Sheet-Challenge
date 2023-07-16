#include <bits/stdc++.h> 
using namespace std;

string longestCommonPrefix(vector<string> &s, int n)
{
    if(n == 0) return "";
    sort(s.begin(), s.end());
    string a = s[0], b = s[n-1];
    string ans = "";
    for(int i = 0; i < a.size(); i++){
        if(a[i] == b[i]) ans += a[i];
        else break;
    }
    return ans;
}
