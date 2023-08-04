/*

//input -> a weighted graph and a source
//output -> distance of all nodes from the source







space complexity = O(n);
time complexity  = O(n^2)
 
 -create a distance array "d"
 - initialize all value of "d" to infinity    ->O(n)
 -d[src] = 0;                                                        d->distance   || c->cost
- create a visited array and mark all node as unvisited         ->O(n)
- pq.push({0,src})
     -while the priority_queue is not empty: ->O(E)
     -head_distance,head = pq.front();
     -pq.pop() -> O(logE)
     -if(visited[head] == 1 :ignore)
     -for all adj_node of head   ->O(E)

     
        -if d[head] + c(head,adj_node) < d[adj_node]:
            -d[adj_node] = d[head] + c(head,adj_node)      ->O(logE)
            -pq.push({d[adj_node],adj_node})   ->O(logE)


-output array "d"  




     w
u--------->v
----------> x
     a

u->   (v,w),(x,a)

*/
//n->  10^5
//m->  10^5
//max_w ->10^6

//10^6 * 10^5 = 10^11

//O(ElogV)
/*
5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1
output
1 4 3 5 

*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const long long INF = 1e18;
vector< pair<int, int> >adj_list[N];
int  visited[N],parent[N];
int nodes,edges;
long long d[N];

void dijkstra(int src)

{
for(int i = 1;i <= nodes;i++)
{
    d[i] = INF;

}


d[src] = 0;
priority_queue<pair<long long int,int>>pq;
pq.push({0,src});

while( !pq.empty())
{

pair<long long,int>head = pq.top();
pq.pop();

int selected_node = head.second;

if(visited[selected_node])
{
    continue;
}
visited[selected_node] = 1;   

  for (auto adj_entry:adj_list[selected_node])       //adj_entry = adj_node
  {
    int adj_node = adj_entry.first;
    int edge_cst = adj_entry.second;

    if(d[selected_node] + edge_cst < d[adj_node])
    {
      d[adj_node] = d[selected_node] + edge_cst;
      parent[adj_node] = selected_node;

         pq.push({-d[adj_node],adj_node});        //- sign use koreci karon priority queue er big value nice takbe small value upor a takbe-
    }                                              //- sign use korar fole je pote kom koroc hobe ta ver kora jabe   

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

if(visited[nodes] == 0)
{
    cout<<-1<<endl;
    return 0;
}

int current_node = nodes;
vector<int>path;
while (true)
{
    path.push_back(current_node);
    if(current_node == src)
    {
        break;
    }
    current_node = parent[current_node];
}
reverse(path.begin(),path.end());
for(int node:path)
{
    cout<<node<<" ";
}
cout<<endl;


// cout<<d[nodes]<<endl;

// for(int i = 1; i<=nodes ;i++)
// {
//  cout<<d[i]<<" ";
// }

// cout<<endl;
return 0;
} 
