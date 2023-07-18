#include <bits/stdc++.h> 
using namespace std;

bool findPattern(string p, string s)
{
    int n = p.size();
    for(int i = 0; i < s.size(); i++){
        if(s[i] == p[0] && (i+n-1) < s.size()){
            string str = s.substr(i, n);
            if(str == p) return true;
        }
    }
    return false;
}