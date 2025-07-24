/*
Prim's Algorithm – Minimum Spanning Tree (MST)

Initial Configuration:
- Maintain an array `edges` to store the MST edges, and a variable `sum` to keep track of the total weight of the MST.
- Use a priority queue (min-heap) to always pick the edge with the smallest weight.
- The queue stores elements in the format: {weight, node, parent}.
  For the initial node (e.g., node 0), push {0, 0, -1} into the queue.
- Maintain a `visited` array to track which nodes have been included in the MST. Initially, all nodes are unvisited.

Process:
1. While the priority queue is not empty:
   - Extract the top element (i.e., the edge with the minimum weight).
   - If the current node has already been visited, skip this iteration.
   - Otherwise:
     - Mark the node as visited.
     - If the parent is not -1, add the edge (parent → current node) to the `edges` array.
     - Add the weight to the `sum`.
   - Traverse all adjacent nodes of the current node.
     - For each unvisited neighbor, push {edge weight, neighbor, current node} into the priority queue.

Intuition:
This algorithm uses a greedy approach. At each step, it chooses the minimum weight edge that connects a visited node to an unvisited node.
By always selecting the lightest possible edge, Prim’s algorithm ensures the resulting tree has the smallest total weight.
*/


#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using pii = pair<int,pair<int,int>>;

void prims(int v,vector<vector<pair<int,int>>>& adj,int& sum, vector<pair<int,int>>& edges)
{
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    vector<int> vis(v,0);
    pq.push({0,{0,-1}});

    while(!pq.empty())
    {
        auto it = pq.top();
        pq.pop();

        int edgeWeight = it.first;
        int node = it.second.first;
        int parent = it.second.second;

        if(vis[node] == 1) continue;

        vis[node] = 1;
        if(parent != -1)
        {
            sum += edgeWeight;
            edges.push_back({node,parent});
        }

        // Explore the neighbours of the current node and push them into the queue if not alreayd visited
        for(auto neighbour:adj[node])
        {
            int adjNode = neighbour.first;
            int edWeight = neighbour.second;
            if(vis[adjNode] == 0)
            pq.push({edWeight,{adjNode,node}});
        }
    }
}

int main()
{
    int n = 5; // number of nodes (0-based indexing)
vector<vector<pair<int, int>>> adj(n); // adj[u] = {{v, weight}, ...}

adj[0].push_back({1, 2});
adj[0].push_back({3, 6});

adj[1].push_back({0, 2});
adj[1].push_back({2, 3});
adj[1].push_back({3, 8});
adj[1].push_back({4, 5});

adj[2].push_back({1, 3});
adj[2].push_back({4, 7});

adj[3].push_back({0, 6});
adj[3].push_back({1, 8});

adj[4].push_back({1, 5});
adj[4].push_back({2, 7});
int sum = 0;
vector<pair<int,int>> edges;
prims(n,adj,sum,edges);
cout<<"The edges that form the Minimum Spanning Tree for the given graph are : \n";
for(auto it:edges)
cout << it.first << "--" << it.second << "\n";
cout << "The sum of the weights of the edges involved in the mst is : "<<sum<<endl;
return 0;
}