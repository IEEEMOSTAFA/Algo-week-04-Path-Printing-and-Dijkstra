#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
struct Edge
{
    int u,v,w;
};
void dijkstra(vector<vector<Edge>>&adj,vector<int>&dist,int src)
{
    dist.assign(adj.size(),INF);
    dist[src] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,src});
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for(auto e : adj[u])
        {
            int v =e.v;
            int w = e.w;

            if(dist[v] >dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v],v});
            }
        }
    }
    
}

int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<Edge>>adj(n);
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({u,v,w});
        adj[v].push_back({v,u,w});
    }
    vector<int>dis(n);
    dijkstra(adj,dis,0);
}