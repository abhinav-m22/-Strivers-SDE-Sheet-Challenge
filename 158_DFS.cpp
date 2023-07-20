#include<bits/stdc++.h>
using namespace std;

void dfs(int i ,vector<int>& temp ,vector<int> adj[], vector<bool>&vis){
    vis[i] = true;
    temp.push_back(i);
    for(auto it : adj[i]){
        if(!vis[it]){
            dfs(it, temp, adj, vis);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<int>adj[V+1];
    for(auto it : edges){
        int x = it[0];
        int y = it[1];
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    vector<bool> vis(V, 0);
    vector<vector<int>> ans;

    for(int i = 0; i < V; i++){
        if(!vis[i]){
            vector<int> temp;
            dfs(i, temp, adj, vis);
            ans.push_back(temp);
        }
    }
    return ans;
}