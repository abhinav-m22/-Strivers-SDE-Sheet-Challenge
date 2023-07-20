#include <bits/stdc++.h>
using namespace std;

void bfs(int i, vector<int> adj[], vector<int>& ans, vector<bool>& vis){
    vis[i] = 1;
    queue<int> q;
    q.push(i);
    while(!q.empty()){
        int t = q.front();
        ans.push_back(t);
        q.pop();
        for(auto it : adj[t]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }
    }
}

vector<int> BFS(int v, vector<pair<int, int>> edges)
{
    vector<int> adj[v+1];
    for(auto it : edges){
        int x = it.first;
        int y = it.second;
        adj[x].push_back(y);
        adj[y].push_back(x); 
    }

    for(int i = 0; i < v; i++){
        sort(adj[i].begin(), adj[i].end());
    }

    vector<bool> vis(v, 0);
    vector<int> ans;
    for(int i = 0; i < v; i++){
        if(!vis[i]){
            bfs(i, adj, ans, vis);
        }
    }
    return ans;
}