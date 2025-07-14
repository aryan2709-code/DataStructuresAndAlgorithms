#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> bfsOfGraph(int v,vector<int> adj[])
{
    int vis[v]= {0}; // a visited array of size v, 0-based indexing
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    vector<int> bfs;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for(int it:adj[node])
        {
            if(!vis[it])
            {
                vis[it] =1;
                q.push(it);
            }
        }
    }
    return bfs;
}
void printArray(vector<int>& arr)
{
    for(int num: arr) cout<<num<<" ";
    cout<<endl;
}
int main()
{
vector<int> adj[6];

adj[0] = {1, 2};
adj[1] = {0, 3};
adj[2] = {0, 4};
adj[3] = {1, 5};
adj[4] = {2};
adj[5] = {3};

vector<int> bfs = bfsOfGraph(6,adj);
printArray(bfs);
return 0;
}

