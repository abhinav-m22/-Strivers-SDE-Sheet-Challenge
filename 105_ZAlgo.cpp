#include<bits/stdc++.h>
using namespace std;

int zAlgorithm(string s, string p, int n, int m)
{
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == p[0] && (i+m-1) < n){
			string str = s.substr(i, m);
			if(str == p) cnt++;
		}
	}
	return cnt;
}