#include <bits/stdc++.h> 
using namespace std;

int kthLargest(vector<int>& arr, int size, int K)
{
	// Write your code here.
	priority_queue<int, vector<int>, greater<int>> pq;
    // Method 1:
	// for(auto it : arr){
	// 	pq.push(it);
	// 	if(pq.size() > K) pq.pop();
	// }
	// return pq.top();

    // Method 2:
	for(int i = 0; i < K; i++) pq.push(arr[i]);
	for(int i = K; i < size; i++){
		if(pq.top() < arr[i]){
			pq.pop();
			pq.push(arr[i]);
		}
	}

	return pq.top();
}