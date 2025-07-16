#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> shortestDistances(int src,int v,vector<int> adj[])
{
    vector<int> dist(v,1e8);
    queue<int> q;
    q.push(src);
    dist[src] = 0;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        int distance = dist[node];

        for(int neighbour:adj[node])
        {
            if(1 + distance < dist[neighbour])
            {
                dist[neighbour] = 1 + distance;
                q.push(neighbour);
            }
        }
    }
    for(int i=0; i<dist.size();i++)
    {
        dist[i] = (dist[i] == 1e8) ? -1 : dist[i];
    }
   return dist;
}
int main()
{
     int v = 9; // Number of nodes (0 to 8)
    vector<int> adj[v];

    // Adding edges (undirected graph)
    adj[0] = {1, 3};
    adj[1] = {0, 2, 3};
    adj[2] = {1, 6};
    adj[3] = {0, 4};
    adj[4] = {3, 5};
    adj[5] = {4, 6};
    adj[6] = {2, 5, 7, 8};
    adj[7] = {6, 8};
    adj[8] = {6, 7};

    vector<int> ans = shortestDistances(0,v,adj);
    for(int num:ans)
    cout<<num<<" ";

    return 0;
}