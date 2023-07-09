#include<bits/stdc++.h>
using namespace std;

void findMedian(int *arr, int n)
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    if(n==0){
        return;
    }
    for(int i = 0; i < n; i++){
        maxHeap.push(arr[i]);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if(minHeap.size() > maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        if(maxHeap.size() > minHeap.size()){
            cout << maxHeap.top() << " ";
        }
        else{
            cout << (maxHeap.top()+minHeap.top())/2 << " ";
        }
    }
    cout << endl;
}