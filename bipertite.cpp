#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> color;
vector<int> visited;
bool bipart;
void colored(int src,int cur)
{
    if(color[src]!=-1 && color[src]!=cur)
    {
        bipart=false;
        return;
    }
    color[src]=cur;
    for(auto v: graph[src])
    {
        if(color[v]==color[src]){bipart=false; return;}
        if(color[v]==-1) 
        {
            colored(v,1-src);
        }
    }
}
int main()
{
    int V,E;cin>>V>>E;
    bipart=true;
    color.resize(V,-1);
    graph.resize(V);
    for(int i=0;i<E;i++)
    {
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=0;i<V;i++)
    {
        if(color[i]==-1) colored(i,0);
    }
    if(bipart) cout<<"Given graph is bipart\n";
    else cout<<"Given graph is not bipart\n";
    return 0;
}