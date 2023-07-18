#include<bits/stdc++.h>
using namespace std;

vector<int> stringMatch(string text, string pattern) {
	int n = pattern.size();
	vector<int> ans;
	for(int i = 0; i < text.size(); i++){
		if(text[i] == pattern[0] && (i+n-1) < text.size()){
			string s = text.substr(i, n);
			if(s == pattern) ans.push_back(i+1);
		}
	}
	return ans;
}
