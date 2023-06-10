#include <bits/stdc++.h>

// Brute Force
long long getInversions(long long *arr, int n)
{
    long long cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                cnt++;
        }
    }
    return cnt;
}

// Optimal - Merge Sort
#include <bits/stdc++.h>
using namespace std;

long long merge(long long *arr, long long s, long long mid, long long e)
{
    long long cnt = 0;
    long long len1 = mid - s + 1;
    long long len2 = e - mid;
    long long first[len1];
    long long second[len2];

    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[s + i];
    }

    for (int j = 0; j < len1; j++)
    {
        second[j] = arr[mid + 1 + j];
    }

    long long index1 = 0;
    long long index2 = 0;
    long long k = s;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] <= second[index2])
        {
            arr[k++] = first[index1++];
        }
        else
        {
            arr[k] = second[index2];
            cnt += len1 - index1;
            k++;
            index2++;
        }
    }
    while (index1 < len1)
    {
        arr[k++] = first[index1++];
    }

    while (index2 < len2)
    {
        arr[k++] = second[index2++];
    }
    return cnt;
}

long long mergesort(long long *arr, long long s, long long e)
{
    long long cnt = 0;
    if (s >= e)
    {
        return 0;
    }
    long long mid = s + (e - s) / 2;
    cnt += mergesort(arr, s, mid);
    cnt += mergesort(arr, mid + 1, e);
    cnt += merge(arr, s, mid, e);
    return cnt;
}

long long getInversions(long long *arr, int n)
{
    return mergesort(arr, 0, n - 1);
}