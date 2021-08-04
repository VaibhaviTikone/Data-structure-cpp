#include<bits/stdc++.h>
using namespace std;
// undirected graph using adjacency matrix
vector<int> d,p;  //d is to store the distance and p is to store parent node
vector<bool> vis; //keep track of visited nodes
void addEdge(vector<int> adj[],int v, int u)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}

void bfs(vector<int> adj[],int s, int v)
{
    queue<int> q;
    q.push(s);
    vis[s]=true;
    p[s]=-1;
    while(!q.empty())
    {
        int v=q.front();
        q.pop();
        for(int u: adj[v])
        {
            if(!vis[u])
            {
                vis[u]=true;
                q.push(u);
                d[u]=d[v]+1;
                p[u]=v;
            }
        }
    }
}

void printGraph(vector<int> adj[],int v)
{
    if(!vis[v]) {cout<<"No path\n"; return;}
    for(int u=v;u!=-1;u=p[u])
        cout<<u<<" ";
    cout<<endl;

}

int main()
{
    int v=5;
    vis.resize(v,false);
    d.resize(v);
    p.resize(v);
    vector<int> adj[v];
    addEdge(adj,0,1);
    addEdge(adj,0,3);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    bfs(adj,0,v);
    printGraph(adj,4); //print path from 4 to source 0
    printGraph(adj,2); //print path from 2 to source 0
    return 0;
}