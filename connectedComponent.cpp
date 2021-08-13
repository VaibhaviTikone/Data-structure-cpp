//find size of connected components and number of components in undirected graph

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<int> components;

//function to find the connected components
int dfs(vector<bool> &vis,int src)
{
    int size=1;
    vis[src]=true;
    for(auto v: graph[src])
    {
        if(!vis[v])
        {
            size+=dfs(vis,v);
        }
    }
    return size;
}
int main()
{
    int V,E;cin>>V>>E;
    graph.resize(V);
    vector<bool> visited(V);
    for(int i=0;i<E;i++)
    {
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=0;i<V;i++)
    {
        if(!visited[i]) 
        components.push_back(dfs(visited,i));
    }
    cout<<"Total connected components: "<<components.size()<<endl;
    cout<<"Size of each components respectively: ";
    for(auto c: components)
    cout<<c<<" ";
    cout<<endl;
    return 0;
}