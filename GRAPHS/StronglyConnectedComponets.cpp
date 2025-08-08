#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/*
Kosaraju's Algorithm – Strongly Connected Components (SCC)

Initial Configuration:
- A Strongly Connected Component (SCC) is a group of nodes in a directed graph 
  where each node is reachable from every other node in that group.
- Kosaraju's algorithm finds all SCCs using two depth-first searches (DFS) and a graph reversal.

Process:
1. First DFS (Original Graph):
   - Create a `visited` array to track visited nodes (initially false for all).
   - Maintain a `stack` to store nodes based on their finishing time.
   - For every unvisited node:
     - Perform DFS and after finishing a node, push it onto the stack.
   - This step determines the correct processing order for the second DFS.

2. Reverse the Graph (Transpose):
   - Create a new adjacency list `transpose` for the reversed graph.
   - For every edge `u → v` in the original graph:
     - Add an edge `v → u` in the transpose.
   - Reversing edges preserves SCC structure but allows us to explore SCCs correctly.

3. Second DFS (Transposed Graph):
   - Reset the `visited` array to false for all nodes.
   - While the stack is not empty:
     - Pop a node from the stack.
     - If it is unvisited:
       - Perform DFS from this node on the transposed graph.
       - All nodes visited in this DFS form one SCC.
       - Store or print the SCC.

Intuition:
- The first DFS captures the "exit times" of nodes so we know which node finishes last.
- Reversing the graph doesn't affect internal connectivity of SCCs.
- The second DFS then groups nodes correctly into SCCs by exploring in finishing-time order.

Time Complexity:
- O(V + E) — Two DFS traversals and one graph reversal.
Space Complexity:
- O(V + E) — For adjacency lists, stack, and visited array.

Kosaraju’s algorithm is efficient, clean, and easy to implement when finding SCCs in directed graphs.
*/

void dfs(int node, vector<int> adj[], vector<int>& vis, stack<int>& st)
{
    vis[node] = 1;

    for(auto it:adj[node])
    {
        if(vis[it] == 0)
        dfs(it,adj,vis,st);
    }

    // After DFS call for the current node is complete, push it in the stack
    st.push(node);
}

void dfsReverse(int node, vector<int> adj[], vector<int>& vis)
{
    vis[node] = 1;
    for(auto it:adj[node])
    {
        if(vis[it] == 0)
        {
            dfsReverse(it,adj,vis);
        }
    }
}

int StronglyConnectedComponents(int v, vector<int> adj[]) // Only exists for directed graphs
{
   stack<int> st;
   vector<int> vis(v,0);

   for(int i=0; i<v; i++)
   {
    if(vis[i] == 0)
    dfs(i,adj,vis,st);
   }

   // Reverse the Graph
   vector<int> adjR[v];
   for(int i=0; i<v; i++)
   {
    // (i -- it) edge exists ---> (it --- i)
    vis[i] = 0;
    for(auto it:adj[i])
    {
        adjR[it].push_back(i);
    }
   }

   int scc = 0;
   while(!st.empty())
   {
    int node = st.top();
    st.pop();
    if(!vis[node])
    {
        scc++;
        dfsReverse(node,adjR,vis);
    }
   }
  return scc;
}

int main()
{
     int V = 8;
    vector<int> adj[V];

    // Directed Graph with 3 SCCs
    // SCC1: 0 ↔ 1 ↔ 2
    // SCC2: 3 ↔ 4
    // SCC3: 5 ↔ 6 ↔ 7
    adj[0] = {1};
    adj[1] = {2};
    adj[2] = {0};
    
    adj[3] = {4};
    adj[4] = {3};
    
    adj[5] = {6};
    adj[6] = {7};
    adj[7] = {5};

    cout << "The number of strongly connected components is : "<< StronglyConnectedComponents(V,adj);
    return 0;
}