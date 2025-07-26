#include<iostream>
#include<vector>
using namespace std;

bool dfsCheck(int node, vector<int> adj[] , int vis[] , int pathVis[])
{
    vis[node] = 1;
    pathVis[node] = 1;

    for(int neighbour : adj[node])
    {
        if(!vis[neighbour])
        {
            if(dfsCheck(neighbour,adj,vis,pathVis)) // if any of the neighbours detect a cycle , return true
            return true;
        }
        else if(pathVis[neighbour]) // if a neighbour node has already been visited and exists on the same path, then there is definitely a cycle
        return true;
    }
    // If none of the neighbours return a true , return false
    // But before that mark the current node as 0 in pathVis array , because it has been visited and will no longer exist on this path
    pathVis[node] = 0;
    return false;
}

bool isCycle(int v,vector<int> adj[])
{
    int vis[v] = {0};
    int pathVis[v] = {0};
    for(int i=0; i<v; i++)
    {
        if(!vis[i])
        {
            if(dfsCheck(i,adj,vis,pathVis))
            return true;
        }
    }
    return false;
}

int main()
{
vector<int> adjWithCycle[5];

adjWithCycle[0] = {1};
adjWithCycle[1] = {2};
adjWithCycle[2] = {3};
adjWithCycle[3] = {1}; // Cycle here: 1 → 2 → 3 → 1
adjWithCycle[4] = {};

vector<int> adjNoCycle[6];
adjNoCycle[0] = {1, 2};
adjNoCycle[1] = {3};
adjNoCycle[2] = {3, 4};
adjNoCycle[3] = {5};
adjNoCycle[4] = {5};
adjNoCycle[5] = {};

cout<< boolalpha;
cout << isCycle(5,adjWithCycle)<<" ";
cout << isCycle(6,adjNoCycle);
return 0;
}