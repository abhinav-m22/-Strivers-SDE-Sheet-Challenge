#include <bits/stdc++.h>

// Brute force
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int missing = -1, repeating = -1;

	for(int i = 1; i <= n; i++){
		int cnt = 0;
		for(int j = 0; j < n; j++){
			if(arr[j] == i) cnt++;
		}
		if (cnt == 2) repeating = i;
        else if (cnt == 0) missing = i;

		if (repeating != -1 && missing != -1) break;
	}
	return {missing, repeating};
}

// Better
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int hash[n+1] = {0};

    for(int i = 0; i < n; i++){
        hash[arr[i]]++;
    }

    int missing = -1, repeating = -1;

    for(int i = 1; i <= n; i++){
        if(hash[i] == 2) repeating = i;
        else if(hash[i] == 0) missing = i;

        if (repeating != -1 && missing != -1) break;
    }

    return {missing, repeating};
}

// Optimal
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    long long int Sum_N = (n * (n+1) ) /2, Sum_NSq = (n * (n + 1) *(2*n + 1)) / 6;
    long long int missingNumber = 0, repeating = 0;
     
    for(int i = 0; i < n; i++){
       Sum_N -= (long long int)arr[i];
       Sum_NSq -= (long long int)arr[i]*(long long int)arr[i];
    }
     
    missingNumber = (Sum_N + Sum_NSq/Sum_N)/2;
    repeating= missingNumber - Sum_N;

    return {missingNumber, repeating};
}