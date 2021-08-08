#include<bits/stdc++.h>
using namespace std;
//valid for directed acyclic graph
//if a graph contains a cycle then we cannot have a topological sort
//if a graph is undirected then there will be multiple valid topological sort.
//Algorithm
/*
1. find the indegree of all the vertices
2. store all the vertices in the queue having indegree as 0.
3. start from the first element of the queue.
    1. pop element. 
    2. decrement its indegree. 
    3. if indegree of this element becomes 0 then store it in queue.
    4. repeat this till queue becomes empty. 
    5. simulteneously print the value stored in queue. 
4. to check the presence of the cycle we can store the values to array. 
    If array is empty or size of array != number of vertices then cycle is present  
*/

vector<int> toposort(vector<vector<int>> &graph,vector<int>& indegree)
{
    int V=graph.size();
    vector<int> ans;
    queue<int> q;
    for(int i=0;i<V;i++)
    {
        if(indegree[i]==0) q.push(i);
    }
    while(!q.empty())
    {
        int u=q.front(); q.pop();
        ans.push_back(u);
        for(auto v: graph[u])
        {
            indegree[v]--;
            if(indegree[v]==0) q.push(v);
        }
    }
    return ans;
}

int main()
{
    int V, E; //number of edges and vertices
    cin>>V>>E;
    vector<vector<int>> graph(V);
    vector<int> indegree(V,0);
    for(int i=0;i<E;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        indegree[v]++;
    }
    vector<int> sorted=toposort(graph,indegree);
    if(sorted.size()==V){
        cout<<"Cycle is not present.\nThe topological sort is as below:\n";
        for(auto &a: sorted)
            cout<<a<<" ";
        cout<<endl;
    } 
    else cout<<"Cycle is present.\n";

    return 0;
}
