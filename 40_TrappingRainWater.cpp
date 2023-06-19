#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time Complexity: O(n^2), Space Complexity: O(1)
long getTrappedWater(long *arr, int n){
    long ans = 0;

    for(int i = 0; i < n; i++){
        int j = i;
        long leftMax = 0, rightMax = 0;

        while(j >= 0){
            leftMax = max(leftMax, arr[j]);
            j--;
        }

        j = i;

        while(j < n){
            rightMax = max(rightMax, arr[j]);
            j++;
        }
        ans += min(leftMax, rightMax) - arr[i];
    }
    return ans;
}

// Better Approach
// Time Complexity: O(3*n) ~ O(n), Space Complexity: O(1)
long getTrappedWater(long *arr, int n){
    long prefix[n], suffix[n];
    prefix[0] = arr[0];
    for(int i = 1; i < n; i++) prefix[i] = max(prefix[i-1], arr[i]);

    suffix[n-1] = arr[n-1];
    for(int i = n-2; i >= 0; i--) suffix[i] = max(suffix[i+1], arr[i]);

    long ans = 0;
    for(int i = 0; i < n; i++){
        ans += min(prefix[i], suffix[i]) - arr[i];
    }

    return ans;
}

// Optimal Approach - 2 pointer
// Time Complexity: O(n), Space Complexity: O(1)
long getTrappedWater(long *arr, int n){
    long left = 0, right = n-1;
    long ans = 0;
    long leftMax = 0, rightMax = 0;

    while(left <= right){
        if(arr[left] <= arr[right]){
            if(arr[left] >= leftMax){
                leftMax = arr[left];
            }
            else{
                ans += leftMax - arr[left];
            }
            left++;
        }
        else{
            if(arr[right] >= rightMax){
                rightMax = arr[right];
            }
            else{
                ans += rightMax - arr[right];
            }
            right--;
        }
    }

    return ans;
}