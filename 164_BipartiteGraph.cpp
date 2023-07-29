#include <bits/stdc++.h>
using namespace std;

bool isGraphBirpatite(vector<vector<int>> &edges)
{
    vector<vector<int>> adj(edges.size());
    for (int i = 0; i < edges.size(); i++)
    {
        for (int j = 0; j < edges[0].size(); j++)
        {
            if (edges[i][j] == 1)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<int> color(edges.size(), 0);
    queue<int> q;
    color[0] = 1;
    q.push(0);

    while (!q.empty())
    {
        auto f = q.front();
        q.pop();
        for (auto child : adj[f])
        {
            if (color[child] == 0)
            {
                color[child] = -color[f];
                q.push(child);
            }
            else if (color[child] == color[f])
                return false;
        }
    }
    return true;
}