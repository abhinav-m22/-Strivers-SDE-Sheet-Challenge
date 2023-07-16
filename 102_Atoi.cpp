#include <bits/stdc++.h> 
using namespace std;

int atoi(string s) {
    int i = 0;
    int ans = 0;
    bool isNegative = false;

    while(i < s.size()){
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) i++;
        else if(s[i] == '-') isNegative = true, i++;
        else if(s[i] >= '0' && s[i] <= '9'){
            int digit = s[i] - '0';
            ans = ans*10 + digit;
            i++;
        }
    }

    if(isNegative) return -ans;

    return ans;
}