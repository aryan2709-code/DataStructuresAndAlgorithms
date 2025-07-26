#include<iostream>
#include<vector>
using namespace std;

void dfs(int node,vector<int> adj[],int vis[],vector<int>& dfsSequence)
{
    vis[node] = 1;
    dfsSequence.push_back(node);

    for(auto it:adj[node])
    {
        if(!vis[it])
        dfs(it,adj,vis,dfsSequence);
    }
}
vector<int> dfsOfGraph(int v,vector<int> adj[])
{
int vis[v] = {0};
vector<int> dfsSequence;
dfs(0,adj,vis,dfsSequence);
return dfsSequence;
}
void printArray(vector<int>& arr)
{
    for(int num: arr) cout<<num<<" ";
}

int main()
{
vector<int> adj[7];
adj[0] = {1, 2};
adj[1] = {0, 3, 4};
adj[2] = {0, 5, 6};
adj[3] = {1};
adj[4] = {1};
adj[5] = {2};
adj[6] = {2};
vector<int> DepthFirstSequence = dfsOfGraph(7,adj);
printArray(DepthFirstSequence);
return 0;
}