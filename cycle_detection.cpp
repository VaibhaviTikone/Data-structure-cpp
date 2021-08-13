//Cycle detection in undirected path using disjointset union (union find method)
//disjointset costs O(n) to find all nodes in set. 
//we can optimize it to O(logn) 
//further optimization will be O(1) with space complexity of O(n)

#include<bits/stdc++.h>
using namespace std;
vector<int> parent;
vector<int> sz;

void makeSet(int v)
{
    parent[v]=v;
    sz[v]=1;
}

int findSet(int v)
{
    if(v==parent[v]) return v;
   // cout<<"findset\n";
    return (parent[v]= findSet(parent[v]));
}

void unionSet(int u, int v)
{
    u=findSet(u);
    v=findSet(v);
    if(u!=v)
    {
        if(sz[u]<sz[v]) swap(u,v);
        parent[v]=u;
        sz[u]+=sz[v];
    }
}

int main()
{
    int V,E; cin>>V>>E;
    parent.resize(V);
    sz.resize(V);
    vector<vector<int>> edges;
    for(int i=0;i<E;i++)
    {
        int u,v; cin>>u>>v;
        edges.push_back({u,v});   
    }
    for(auto e: edges)
    {
        cout<<e[0]<<" "<<e[1]<<endl;

    }
    bool cycle=false;
    for(int i=0;i<V;i++)
    {
        makeSet(i);
    }
    cout<<"Testing\n";
    for(auto e: edges)
    {
        int x=findSet(e[0]);
        int y=findSet(e[1]);
        if(x==y) cycle=true;
        else{ unionSet(e[0],e[1]);}
    }

    if(cycle) cout<<"Cycle is present\n";
    else cout<<"Cycle is not present\n";
    return 0;
}