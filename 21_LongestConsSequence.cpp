#include <bits/stdc++.h>
using namespace std;

// Brute force - O(n * log(n))
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    sort(arr.begin(), arr.end());
    int ans = 1;
    int prev = arr[0];
    int cur = 1;

    for(int i = 1; i < n; i++){
        if(arr[i] == prev+1) cur++;
        else if(arr[i] != prev) cur = 1;

        prev = arr[i];
        ans = max(ans, cur);
    }
    return ans;
}

// Optimal - O(n)
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    unordered_set<int> s;
    for(auto it : arr) s.insert(it);

    int longestStreak = 0;

    for(int num: arr){
        if(!s.count(num-1)){
            int currentNum = num;
            int currentStreak = 1;

            while(s.count(currentNum+1)){
                currentStreak++;
                currentNum++;
            }
            longestStreak = max(longestStreak, currentStreak);
        }
    }
    return longestStreak;
}