#include <bits/stdc++.h> 
using namespace std;

// Time Complexity: O(N^2)
void getMax(vector<int> &nums, int l, int r, vector<int> &arr){
    int maxi = -1;
    for(int i = l; i <= r; i++){
        maxi = max(maxi, nums[i]);
    }
    arr.push_back(maxi);
}

vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    vector<int> arr;
    int n = nums.size();
    int left = 0, right = 0;
    while(right < k-1) right++;

    while(right < n){
        getMax(nums, left, right, arr);
        left++;
        right++;
    }

    return arr;
}

// Time Complexity: O(N)
vector<int> slidingWindowMaximum(vector<int> &nums, int &k){
    deque<int> dq;
    vector<int> ans;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
      if (!dq.empty() && dq.front() == i - k)
        dq.pop_front();

      while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();

      dq.push_back(i);

      if (i >= k - 1)
        ans.push_back(nums[dq.front()]);
    }
    return ans;
}