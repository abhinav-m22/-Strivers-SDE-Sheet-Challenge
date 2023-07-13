#include <bits/stdc++.h> 
using namespace std;

void sortedInsert(stack<int>& s, int x){
	if(s.empty() || (!s.empty() && s.top() < x)){
		s.push(x);
		return;
	}

	int num = s.top();
	s.pop();
	sortedInsert(s, x);

	s.push(num);
}

void sortStack(stack<int> &s)
{
	if(s.empty()) return;
	int num = s.top();
	s.pop();
	sortStack(s);
	sortedInsert(s, num);
}