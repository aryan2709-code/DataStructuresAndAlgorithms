#include<iostream>
#include<vector>
using namespace std;

bool detectCycle(int node,int parent,vector<int> adj[],int vis[])
{
    // mark the current node as visited
    vis[node] = 1;
    for(int neighbour:adj[node])
    {
        if(!vis[neighbour])
        {
            if(detectCycle(neighbour,node,adj,vis))
            return true;
        }
        else if(neighbour != parent)
        {
            return true;
        }
    }
    // If a loop was not detected , return false
    return false;
}

bool isCycle(int v, vector<int> adj[])
{
    int vis[v] = {0};
    for(int i=0; i<v; i++)
    {
        if(!vis[i])
        {
           if(detectCycle(i,-1,adj,vis))
           return true;
        }
        
    }
    return false;
}

int main()
{
    // 1. Single Component Graph with Cycle
    cout << "Graph 1: Single Component with Cycle\n";
    vector<int> adj1[5];
    adj1[0] = {1};
    adj1[1] = {0, 2};
    adj1[2] = {1, 3};
    adj1[3] = {2, 4};
    adj1[4] = {3, 1}; // back edge to create cycle
    

    // 2. Multi Component Graph, one component has a cycle
    cout << "Graph 2: Multi Component, one with Cycle\n";
    vector<int> adj2[6];
    // Component 1 with cycle
    adj2[0] = {1};
    adj2[1] = {0, 2};
    adj2[2] = {1, 0}; // cycle 0-1-2-0
    // Component 2 without cycle
    adj2[3] = {4};
    adj2[4] = {3, 5};
    adj2[5] = {4};
 

    // 3. Single Component Graph without Cycle (Tree)
    cout << "Graph 3: Single Component without Cycle\n";
    vector<int> adj3[5];
    adj3[0] = {1, 2};
    adj3[1] = {0};
    adj3[2] = {0, 3};
    adj3[3] = {2, 4};
    adj3[4] = {3}; // tree-like, no cycles


    // 4. Multi Component Graph without Cycles (Forest)
    cout << "Graph 4: Multi Component without Cycles\n";
    vector<int> adj4[6];
    // Component 1
    adj4[0] = {1};
    adj4[1] = {0};
    // Component 2
    adj4[2] = {3};
    adj4[3] = {2};
    // Component 3
    adj4[4] = {5};
    adj4[5] = {4};
    cout << boolalpha;
    cout << isCycle(5,adj1) << " " << isCycle(6,adj2) << " " << isCycle(5,adj3) << " " << isCycle(6,adj4) <<endl;
    return 0;
}