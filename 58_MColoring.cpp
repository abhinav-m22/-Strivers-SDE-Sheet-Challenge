#include<bits/stdc++.h>
using namespace std;

bool isPossible(int node, vector<vector<int>> &mat, int m, int col, vector<int> &color)
{
    for (int i = 0; i < mat.size(); i++)
    {
        if (i != node && mat[node][i] == 1 && color[i] == col)
            return false;
    }
    return true;
}
bool f(int node, vector<vector<int>> &mat, int m, vector<int> color)
{
    if (node == mat.size())
        return true;
    for (int i = 1; i <= m; i++)
    {
        if (isPossible(node, mat, m, i, color))
        {
            color[node] = i;
            if (f(node + 1, mat, m, color))
                return true;
            color[node] = 0;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m)
{
    // Write your code here
    int n = mat.size();
    vector<int> color(n, 0);
    if (f(0, mat, m, color))
        return "YES";
    return "NO";
}