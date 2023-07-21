#include <bits/stdc++.h>
using namespace std;

vector<long> nextSmaller(vector<int> &arr, long n)
{
    stack<long> s;
    s.push(-1);
    vector<long> v(n);

    for (long i = n - 1; i >= 0; i--)
    {
        long curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
            s.pop();
        v[i] = s.top();
        s.push(i);
    }

    return v;
}

vector<long> prevSmaller(vector<int> &arr, long n)
{
    stack<long> s;
    s.push(-1);
    vector<long> v(n);

    for (long i = 0; i < n; i++)
    {
        long curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
            s.pop();
        v[i] = s.top();
        s.push(i);
    }

    return v;
}

int largestRectangle(vector<int> &heights)
{
    // Write your code here.
    long n = heights.size();
    vector<long> next(n);
    vector<long> prev(n);
    next = nextSmaller(heights, n);
    prev = prevSmaller(heights, n);

    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int l = heights[i];
        if (next[i] == -1)
            next[i] = n;
        int b = next[i] - prev[i] - 1;
        int newArea = l * b;
        area = max(area, newArea);
    }
    return area;
}