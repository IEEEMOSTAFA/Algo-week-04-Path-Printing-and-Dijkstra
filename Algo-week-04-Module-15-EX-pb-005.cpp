/*
10 8
1 3
3 4 
3 6
4 6
2 5
1 7
3 10
9 8	
YES

8 6
7 4
7 6 
4 6
2 5
1 3
7 8
NO
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int>adj_list[N];
bool visited[N];
void bfs(int src)
{
visited[src] = true;
queue<int>q;
q.push(src);
while (!q.empty())
{
 int head = q.front();
 q.pop();
 for(auto adj_node : adj_list[head])
 {
    if(visited[adj_node] == false)
    {
        visited[adj_node] = true;
        q.push(adj_node);
    }
 }
}

}
int main()
{
int nodes,edges;
cin>>nodes>>edges;
for(int i=0;i<edges;i++)
{
    int u,v;
    cin>>u>>v;
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);

}
bfs(1);
if(visited[nodes])
{
    cout<<"Yes";
    return 0;
}
cout<<"No";
return 0;
}