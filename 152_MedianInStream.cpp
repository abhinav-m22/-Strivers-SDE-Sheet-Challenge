#include<bits/stdc++.h>
using namespace std;

vector<int> findMedian(vector<int> &arr, int n){
	
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	
	vector<int> v;
	for(int i = 0; i < n; i++){
		maxHeap.push(arr[i]);
		minHeap.push(maxHeap.top());
		maxHeap.pop();

		if(minHeap.size() > maxHeap.size()){
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}

		if(maxHeap.size() > minHeap.size()){
            v.push_back(maxHeap.top());
        }
		else v.push_back((maxHeap.top() + minHeap.top()) / 2);
	}
	return v;
}
