// Dijkstra Algorithm is not applicable for graph having negative edge weight(s);

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> dijkstra(int v, vector<vector<int>> adj[] , int src)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // {Dist,Node}
    vector<int> dist(v,1e9);
    dist[src] = 0;
    pq.push({0,src});
    while(!pq.empty())
    {
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it:adj[node])
        {
            int edgeWeight = it[1];
            int adjNode = it[0];

            if(distance + edgeWeight < dist[adjNode] )
            {
                dist[adjNode] = distance + edgeWeight;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }
    return dist;
}

void printArray(vector<int>& nums)
{
    for(int num: nums) cout << num << " ";
    cout<<endl;
}

int main()
{
    int v = 5;
vector<vector<int>> adj[v];

// {neighbour, weight}
adj[0].push_back({1, 2});
adj[0].push_back({2, 4});
adj[0].push_back({3, 7});

adj[1].push_back({2, 1});

adj[2].push_back({3, 3});
adj[2].push_back({4, 5});

// adj[3] and adj[4] are empty

vector<int> shortestDistances = dijkstra(v,adj,0);
printArray(shortestDistances);
return 0;
}
