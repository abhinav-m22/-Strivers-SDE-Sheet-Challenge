#include<bits/stdc++.h>
using namespace std;

// Brute Force - O(n^2)
int calculateMinPatforms(int at[], int dt[], int n) {
    int ans = 1;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = i+1; j < n; j++){
            if((at[i] >= at[j] && at[i] <= dt[j]) || (at[j] >= at[i] && at[j] <= dt[i])) cnt++;
        }

        ans = max(ans, cnt);
    }
    return ans;;
}

// Time Complexity - O(nlogn)
int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at, at+n);
    sort(dt, dt+n);

    int ans = 1;
    int cnt = 1;
    int i = 1, j = 0;
    while(i < n && j < n){
        if(at[i] <= dt[j]){
            cnt++, i++;
        }
        else{
            cnt--, j++;
        }

        ans = max(ans, cnt);
    }

    return ans;
}