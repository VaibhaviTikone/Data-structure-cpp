#include<bits/stdc++.h>
using namespace std;
// undirected graph using adjacency matrix
vector<bool> vis; //keep track of visited nodes
void addEdge(vector<int> adj[],int v, int u)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}

void dfs(vector<int> adj[],int s)
{
    vis[s]=true;
    cout<<s<<" ";
    for(auto u: adj[s])
    {
        if(!vis[u]) dfs(adj,u);
    }
    cout<<endl;
}



int main()
{
    int v=5;
    vis.resize(v,false);
    vector<int> adj[v];
    addEdge(adj,0,1);
    addEdge(adj,0,3);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    dfs(adj,0);
    return 0;
}