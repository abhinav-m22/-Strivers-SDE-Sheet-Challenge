#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
int subarraysXor(vector<int> &arr, int x)
{
    int n = arr.size();
    int cur = 0;
    int k = 0;
    for(int i = 0; i < n; i++){
        cur = arr[i];
        if(cur == x) k++;
        for(int j = i+1; j < n; j++){
            cur = cur ^ arr[j];
            if(cur == x) k++;
        }
    }

    return k;
}

// Optimal: T.C - O(N) or O(N*logN) depending on which map data structure we are using, where N = size of the array.
int subarraysXor(vector<int> &arr, int k){
    int n = arr.size(); 
    int xr = 0;
    map<int, int> mpp; 
    mpp[xr]++; 

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        xr = xr ^ arr[i];

        int x = xr ^ k;

        cnt += mpp[x];

        mpp[xr]++;
    }
    return cnt;
}