#include<bits/stdc++.h>
using namespace std;

// Brute Force - Time Complexity: O(m+n)
double median(vector<int>& a, vector<int>& b) {
    int m = a.size();
    int n = b.size();
    int arr[n+m];
    int i = 0, j = 0, k = 0;

    while(i < m && j < n){
        if(a[i] < b[j]) arr[k++] = a[i++];
        else arr[k++] = b[j++];
    }
    while(i < m){
        arr[k++] = a[i++];
    }
    while(j < n){
        arr[k++] = b[j++];
    }

    n = n+m;
    if(n%2) return arr[((n+1)/2)-1];
    return ((float)arr[(n/2-1)]+(float)arr[(n/2)])/2;
}

// Optimized - Time Complexity: O(log(min(m,n))) - Binary Search
double median(vector<int>& a, vector<int>& b){
    int m = a.size(), n = b.size();
    int low = 0, high = m, medianPos = ((m+n)+1)/2;

    while(low <= high){
        int cut1 = (low + high) >> 1;
        int cut2 = medianPos - cut1;
        int l1 = (cut1 == 0) ? INT_MIN : a[cut1-1];
        int l2 = (cut2 == 0) ? INT_MIN : b[cut2-1];
        int r1 = (cut1 == m) ? INT_MAX : a[cut1];
        int r2 = (cut2 == n) ? INT_MAX : b[cut2];

        if(l1 <= r2 && l2 <= r1){
            if((m+n)%2 != 0) return max(l1, l2);
            else return (max(l1, l2) + min(r1, r2))/2.0;
        }
        else if(l1 > r2) high = cut1-1;
        else low = cut1+1;
    }

    return 0.0;
}