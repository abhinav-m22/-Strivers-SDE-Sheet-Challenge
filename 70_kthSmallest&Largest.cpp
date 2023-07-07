#include<bits/stdc++.h>
using namespace std;
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	// Write your code here.
    // solution 1
	sort(arr.begin(),arr.end());
    return {arr[k-1],arr[n-k]};

    // solution 2
	vector<int> res;
	priority_queue<int> pq;
	priority_queue<int,vector<int>,greater<int>> pq1;
	for(int i=0; i < n ; i++){
		pq.push(arr[i]);
		pq1.push(arr[i]);
		if(pq.size() > k) pq.pop();
		if(pq1.size()> k) pq1.pop();
	}
	return {pq.top(),pq1.top()};
}