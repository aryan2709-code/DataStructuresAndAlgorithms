/*
Tarjan's Algorithm – Finding Bridges in an Undirected Graph

Definition:
- A **bridge** (or **cut-edge**) is an edge in an undirected graph whose removal increases 
  the number of connected components. In other words, it disconnects part of the graph.

Core Idea:
- Tarjan’s algorithm uses Depth First Search (DFS) to find bridges in linear time.
- It assigns two timestamps to every node:
  1. `tin[u]` – time of first visit of node `u`.
  2. `low[u]` – the lowest reachable discovery time from the subtree rooted at `u`,
     including its back edges.

Bridge Detection Logic:
- For an edge `u → v`, after DFS on `v`, if `low[v] > tin[u]`, then the edge (u, v) is a bridge.
  This means that there is no way from the subtree of `v` to reach `u` or any of its ancestors 
  without using the edge `u → v`.

Algorithm Steps:
1. Initialize:
   - Arrays: `tin[]`, `low[]`, `vis[]` for timestamps, lowest time, and visited status.
   - Global `timer` to track DFS discovery time.
2. DFS Traversal:
   - For each unvisited node, run DFS:
     - Set `tin[node] = low[node] = timer++`
     - Recursively visit all neighbors except parent.
     - Update `low[node]` from children or back edges.
     - If `low[neighbour] > tin[node]`, then mark (node, neighbour) as a bridge.
3. Handle Disconnected Graphs:
   - Run DFS from every unvisited node (outer loop over all nodes) to ensure full coverage.

Time Complexity:
- O(V + E) – Linear in the number of vertices and edges (due to DFS traversal).

Space Complexity:
- O(V + E) – For adjacency list and auxiliary arrays.

Note:
- Tarjan's bridge-finding algorithm is different from its articulation point variant, 
  though they share the same DFS foundation.
*/


#include<iostream>
#include<vector>
using namespace std;

// Global timer
int timer = 1;
void dfs(int node, int parent,vector<int>& vis,vector<int> adj[],vector<int>& low,vector<int>& tin,vector<vector<int>>& bridges)
{
    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;
    for(auto it:adj[node])
    {
        if(it == parent) continue;
        
        if(vis[it] == 0)
        {
            dfs(it,node,vis,adj,low,tin,bridges);
            // After the dfs call is complete,it would have its low[] updated
            // we will borrow its low and then check whether, if this edge can be a bridge
            low[node] = min(low[node],low[it]);
            // node ---- it
            if(low[it] > tin[node])
            {
                bridges.push_back({node,it});
            }
        }
        else // If the neighbouring node is already visited, then it cannot be a bridge for sure, because someone else can reach there before
        // the current node, so there exists another way of reaching there
        {
            // Update the low
            low[node] = min(low[node],low[it]);
        }
    }
}
vector<vector<int>> bridgesInGraph(int v, vector<vector<int>>& edges) // v vertices and edges
{
    vector<int> adj[v];
    for(auto it:edges)
    {
        // Undirected Graph
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]); 
    }

    vector<int> vis(v,0);
    vector<int> tin(v);
    vector<int> low(v);

    vector<vector<int>> bridges;
   for (int i = 0; i < v; i++) {
    if (!vis[i]) {
        dfs(i, -1, vis, adj, low, tin, bridges);
    }
}
    return bridges;
}

int main()
{
    int V = 7;

vector<vector<int>> edges = {
    {0, 1},
    {1, 2},
    {2, 0},  // forms a cycle with 0-1-2
    {1, 3},
    {3, 4},
    {4, 5},
    {5, 6},
    {6, 3}   // forms a cycle with 3-4-5-6
};

vector<vector<int>> bridges = bridgesInGraph(V,edges);
// Print these bridges
for(auto it:bridges)
cout << it[0] << " -- "<<it[1]<<endl;

return 0;
}