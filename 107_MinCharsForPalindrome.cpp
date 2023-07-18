#include<bits/stdc++.h>
using namespace std;

// Solution 1:
int minCharsforPalindrome(string str) {
	int n = str.size();
	int i = 0, j = n-1;
	int e2 = j, cnt = 0;
	while(i < j){
		if(str[i] == str[j]){
			i++, j--;
		}
		else{
			cnt++;
			i = 0;
			e2--;
			j = e2;
		}
	}
	return cnt;
}

// Solution 2:
bool isPalindrome(int st, int end, string &str){
    while(st < end){
        if(str[st] != str[end]) return false;
        st++;
        end--;
    }
    return true;
}

int minCharsforPalindrome(string str) {
	int n = str.size();
	int i = n-1;
	while(i > 0){
		if(str[i] == str[0]){
			if(isPalindrome(0, i, str)) return n-i-1;
		}
		i--;
	}
	return n-1;
}
