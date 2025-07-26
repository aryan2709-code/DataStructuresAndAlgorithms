/*
Nodes on whose removal, the grpah breaks down into multiple components

It is a follow up of the bridges code,
tin[] - stores the time of insertion during DFS
low[] - stores the minimum of lows of all adjacent nodes except parent and ***** Visited Nodes *****
In case of visited nodes, the current node will update its low with the *** insertion time *** of the visited node
Updated condition : if(low[it] >= tin[node] && parent != -1)
we have to avoid the formula on the starting nodes (parent is -1), In case of parents, if the number of children is more than one ,
them it will surely be an articulation point, because its removal will automatically lead to creation of multiple components,
and the equal to  in the condition signifies that even if we reach the node,that is of no use, because the node is going to be removed anyways
 ,so you must reach the node before the parent. The low time of the neighbour,node should be strictly lesser than the time of insertion of the current node
*/

#include<iostream>
#include<vector>
using namespace std;
int timer = 0;
void dfs(int node,int parent,vector<int>& vis,int tin[],int low[],vector<int>& mark,vector<int> adj[])
{
    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;
    int child = 0;
    for(auto it:adj[node])
    {
        if(it == parent) continue;

        if(!vis[it]) // if the neighbour is not visited
        {
            dfs(it,node,vis,tin,low,mark,adj);
            low[node] = min(low[node],low[it]);
            if(low[it] >= tin[node] && parent != -1) // if the neighbour node is not able to visit a node better than the current node, then the current node
            // is an articulation point
            {
               mark[node] = 1;
            }
            child++;
        }
        else // if the neighbour is already visited, this time we will not take its low, instead we will take its insertion time
        {
            low[node] = min(low[node],tin[it]);
        }
    }
    if(child > 1 && parent == -1) // starting node having multiple children is an articulation point
    mark[node] = 1;
}

vector<int> articulationPoints(int v,vector<int> adj[])
{
    vector<int> vis(v,0);
    int tin[v];
    int low[v];
    vector<int> mark(v,0);
    for(int i=0; i<v; i++)
    {
        if(!vis[i])
        {
           dfs(i,-1,vis,tin,low,mark,adj);
        }
    }
    vector<int> ans;
    for(int i=0; i<v; i++)
    {
        if(mark[i] == 1)
        ans.push_back(i);
    }
    if(ans.size() == 0)
    ans.push_back(-1);

    return ans;
}

int main()
{
int V = 8;
vector<int> adj[V];

adj[0] = {1};
adj[1] = {0, 2, 3};
adj[2] = {1};
adj[3] = {1, 4};
adj[4] = {3, 5, 6};
adj[5] = {4};
adj[6] = {4, 7};
adj[7] = {6};


vector<int> ans = articulationPoints(V,adj);
cout << "The articulation points are : ";
for(int num:ans) cout << num << " ";
return 0;
}

