#include <bits/stdc++.h>
using namespace std;

// Time complexity: O(n*log(n))+O(n), Space Complexity: O(n)
int removeDuplicates(vector<int> &arr, int n)
{
    set<int> set;
    for (int i = 0; i < n; i++)
    {
        set.insert(arr[i]);
    }
    int k = set.size();
    int j = 0;
    for (int x : set)
    {
        arr[j++] = x;
    }
    return k;
}

// Time complexity: O(n), Space Complexity: O(1)
int removeDuplicates(vector<int> &arr, int n) {
	int i = 0;
    for(int j = 1; j < n; j++){
        if(arr[i] != arr[j]){
            i++;
            arr[i] = arr[j];
        }
    }
    return i+1;
}