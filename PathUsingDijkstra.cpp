#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> pathUsingDijkstra(int n , int m , vector<vector<int>> edges)
{
    // First of all, form an adjacency list
    vector<pair<int,int>> adj[n+1]; // 1- based indexing
    // Iterate over the edges and form the graph
    for(auto it: edges)
    {
        int node1 = it[0];
        int node2 = it[1];
        int weight = it[2];

        adj[node1].push_back({node2,weight});
        adj[node2].push_back({node1,weight});
    }

    // After forming the graph, initialise a distance array and a parent array to get the final path
    vector<int> dist(n+1,1e9),parent(n+1);
    for(int i=1; i<parent.size(); i++) parent[i] = i; //Initialise every member of the parent array to itself initially
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; 

    dist[1] = 0; // In this problem 1 is considered as the source node and n is considered as the destination node
    pq.push({0,1}); // {dist,src}
    while(!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        //Iterate over the neighbours
        for(auto it:adj[node])
        {
            int adjNode = it.first;
            int edgeWeight = it.second;

            if(dis + edgeWeight < dist[adjNode] )
            {
                parent[adjNode] = node;
                dist[adjNode] = dis + edgeWeight;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }

    // After doing all of this , we will have our distances array and parents array with us
    vector<int> path;
    int node = n;
    while(parent[node] != node)
    {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1);
    
    reverse(path.begin(),path.end());
    
    return path;
}

int main()
{
    int n = 6, m = 7;

vector<vector<int>> edges = {
    {1, 2, 4},
    {1, 3, 2},
    {2, 3, 5},
    {2, 4, 10},
    {3, 5, 3},
    {5, 4, 4},
    {4, 6, 11}
};

vector<int> path = pathUsingDijkstra(n,m,edges);
for(auto it:path) cout<<it<<" ";
return 0;
}