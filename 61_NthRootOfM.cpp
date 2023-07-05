#include<bits/stdc++.h>
using namespace std;


// Brute Force: Time Complexity: O(M*log(n))
int func(int b, int exp){
    long long ans = 1;
    long long base = b;

    while(exp > 0){
        if(exp%2){
            exp--;
            ans = ans*base;
        }
        else{
            exp /= 2;
            base = base*base;
        }
    }
    return ans;
}

int NthRoot(int n, int m) {
    for(int i = 1; i <= m; i++){
        long long val = func(i, n);
        if(val == m*1ll) return i;
        else if(val > m*1ll) break;
    }
    return -1;
}

int func(int mid, int n, int m){
    long long ans = 1;
    for(int i = 1; i <= n; i++){
        ans = ans*mid;
        if(ans > m) return 2;
    }
    if(ans == m) return 1;
    return 0;
}

// Optimal - Binary Search: Time Complexity: O(logN)
int NthRoot(int n, int m) {
    int low = 1, high = m;

    while(low <= high){
        int mid = (low+high)/2;
        int midN = func(mid, n, m);
        if(midN == 1) return mid;
        else if(midN == 0) low = mid+1;
        else high = mid-1;
    }

    return -1;
}