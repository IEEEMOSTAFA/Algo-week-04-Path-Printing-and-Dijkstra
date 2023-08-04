

/*
3 2
1 2
2 3
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3;
int visited[N];
vector<int>adj_list[N];
bool bfs(int src)
{
    queue<int>q;
    q.push(src);
    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        for(auto adj_node:adj_list[head])
        {
            if(visited[adj_node] == -1)
            {
                visited[adj_node] = 1;
                q.push(adj_node);
            }
            else if(visited[adj_node]== 1)
            {
                return true;
            }
        }
        visited[head] = 0;

    }
    return false;
    
}
int main()
{
    for(int i=0;i<N;i++)
    {
        visited[i] = -1;
    }
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);

    }
    
   if(bfs(1))
   {
    cout<<"cycle Exist";
    return 0;
   }
   cout<<" No cycle ";
   return 0;
    

}