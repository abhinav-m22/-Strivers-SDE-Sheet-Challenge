#include<bits/stdc++.h>
using namespace std;

// Brute Force - Time Complexity: O(row*col log(row*col))
int getMedian(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> v;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            v.push_back(matrix[i][j]);
        }
    }
    sort(v.begin(), v.end());
    return v[(n*m)/2];
}

int findSmallerThanMid(vector<int>& row, int mid){
    int l = 0, h = row.size() - 1;
    while(l <= h){
        int md = (l + h) >> 1;
        if(row[md] <= mid) l = md+1;
        else h = md-1;
    }
    return l;
}

// Optimal - Binary Search: Time Complexity: O(row*log col)
int getMedian(vector<vector<int>> &matrix){
    int low = 1;
    int high = 1e9;
    int n = matrix.size();
    int m = matrix[0].size();

    while(low <= high){
        int mid = (low + high) >> 1;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            cnt += findSmallerThanMid(matrix[i], mid);
        }

        if(cnt <= (n*m)/2) low = mid+1;
        else high = mid-1;
    }
    return low;
}