#include <bits/stdc++.h>

bool dfs(int v, vector<int> &visited, vector<int> &path, vector<vector<int>> &ad)
{

    visited[v] = 1;

    path[v] = 1;

    for (auto n : ad[v])
    {

        if (visited[n] == 1)
        {

            if (path[n] == 1)
                return true;
        }
        else
        {

            if (dfs(n, visited, path, ad))
                return true;
        }
    }

    path[v] = 0;

    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{

    // Write your code here.

    vector<vector<int>> ad(n + 1);

    for (int i = 0; i < edges.size(); i++)
    {

        int u = edges[i].first, v = edges[i].second;

        ad[u].push_back(v);
    }

    vector<int> visited(n + 1, 0);

    vector<int> path(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {

        if (visited[i] == 0)
        {

            if (dfs(i, visited, path, ad))
                return 1;
        }
    }

    return 0;
}