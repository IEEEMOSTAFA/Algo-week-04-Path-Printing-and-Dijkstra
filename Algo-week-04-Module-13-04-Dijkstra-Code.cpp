/*

//input -> a weighted graph and a source
//output -> distance of all nodes from the source







space complexity = O(n);
time complexity  = O(n^2)
 
 -create a distance array "d"
 - initialize all value of "d" to infinity 
 -d[src] = 0;                                                        d->distance   || c->cost
- create a visited array and mark all node as unvisited
- for i =0  to n-1
     -pick the unvisited node with the minimum d[node]
     -visited[node] = 1;
     -for all adj_node of node:
        -if d[node] + c(node,adj_node) < d[adj_node]:
            -d[adj_node] = d[node] + c(node,adj_node)


-output array "d"  




     w
u--------->v
----------> x
     a

u->   (v,w),(x,a)

*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int INF = 1e9;
vector< pair<int, int> >adj_list[N];
int d[N], visited[N];
int nodes,edges;

void dijkstra(int src)

{
for(int i = 1;i <= nodes;i++)
{
    d[i] = INF;

}

d[src] = 0;

for(int i=0;i<nodes;i++)
{
  int selected_node = -1;
  for(int j= 1;j<= nodes;j++)
  {
    if(visited[j] == 1) continue;
    //selected_node = 2;
    //j = 4;
    //d[2] > d[4]  -> selected_node = 4


    if(selected_node = -1 || d[selected_node] > d[j])
    {
        selected_node = j;
    }
  }
  visited[selected_node] = 1;   
  for (auto adj_entry:adj_list[selected_node])       //adj_entry = adj_node
  {
    int adj_node = adj_entry.first;
    int edge_cst = adj_entry.second;

    if(d[selected_node] + edge_cst < d[adj_node])
    {
      d[adj_node] = d[selected_node] + edge_cst;

    }

  }

  
}
}
int main()
{

cin>>nodes>>edges;
for(int i =0;i<edges;i++)
{
    int u,v,w;   //jeheto ata weighted graph tai etate weight takbe
    cin>>u>>v>>w;
    adj_list[u].push_back({v, w});

    adj_list[v].push_back({u, w});
  
     
}
int src = 1;
dijkstra(src);
for(int i = 1; i<=nodes ;i++)
{
 cout<<d[i]<<" ";
}
cout<<endl;
return 0;
} 
