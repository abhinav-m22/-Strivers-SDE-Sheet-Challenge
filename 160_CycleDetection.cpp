#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, vector<int> adj[], int *vis){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            if(dfs(it, node, adj, vis) == true) return true;
        }
        else if(it != parent) return true;
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<int> adj[n+1];
    for(auto it : edges){
        int x = it[0];
        int y = it[1];
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int vis[n+1] = {0}; 

    for(int i = 0; i < n; i++){
        if(!vis[i]){
            if(dfs(i, -1, adj, vis) == true) return "Yes";
        }
    }

    return "No";
}
