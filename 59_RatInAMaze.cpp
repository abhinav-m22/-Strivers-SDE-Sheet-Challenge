#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(4^(m*n))
void solve(int i, int j, int n, vector<vector<int>> &maze, vector<vector<int>> &vis, vector<vector<int>> &ans)
{
    if (i < 0 || j < 0 || i >= n || j >= n || vis[i][j] == 1 || maze[i][j] == 0)
        return;

    if (i == n - 1 && j == n - 1)
    {
        vector<int> temp;
        vis[i][j] = 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                temp.push_back(vis[i][j]);
            }
        }

        vis[i][j] = 0;
        ans.push_back(temp);

        return;
    }

    vis[i][j] = 1;

    solve(i - 1, j, n, maze, vis, ans);
    solve(i + 1, j, n, maze, vis, ans);
    solve(i, j - 1, n, maze, vis, ans);
    solve(i, j + 1, n, maze, vis, ans);

    vis[i][j] = 0;
}

vector<vector<int>> ratInAMaze(vector<vector<int>> &maze, int n)
{
    vector<vector<int>> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));

    if (maze[0][0] == 0)
        return ans;

    solve(0, 0, n, maze, vis, ans);

    return ans;
}