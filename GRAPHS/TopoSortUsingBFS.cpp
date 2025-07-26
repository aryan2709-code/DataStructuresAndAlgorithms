#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// Also known as Kahn's Algorithm

// This concept can also be used for cycle detection in directed graphs, as we know that topo sort is only possible for DAGs, if we try to implement
// topo sort for a directed cyclic graph, then the number of nodes in the final sequence will always be less than the total number of nodes , and this
// fact can be used for detecting a cycle in a directed graph.
vector<int> topoSort(int v,vector<int> adj[])
{
    int indegree[v] = {0};
    for(int i=0; i<v;i++)
    {
        for(int neighbour:adj[i])
        {
            indegree[neighbour]++;
        }
    }
    // Push all the nodes having indegree 0 in the queue, these will occupy the starting positions in the sequence
    queue<int> q;
    for(int i=0; i<v;i++)
    {
        if(indegree[i] == 0)
        q.push(i);
    }
    vector<int> topo;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        // Remove the contribution of this node in the indegree of its neighbouring nodes as it has already been included in the topo sequence,
        // so this node won't affect its arrival in the topo sequence anymore, in a way we are breaking the outgoing edges from this node
        for(int neighbour:adj[node])
        {
            indegree[neighbour]--;
            if(indegree[neighbour] == 0)
            q.push(neighbour);
        }
    }
    return topo;
}

void printArray(vector<int>& arr)
{
    for(int num:arr) cout<<num<<" ";
    cout<<"\n";
}

int main()
{
vector<int> adj[4];
adj[0] = {1, 2};
adj[1] = {3};
adj[2] = {3};
adj[3] = {};

vector<int> ans = topoSort(4,adj);
printArray(ans);
return 0;
}