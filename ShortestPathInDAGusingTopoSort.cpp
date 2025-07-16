#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void toposort(int node,vector<pair<int,int>> adj[],int vis[],stack<int>& st)
{
    vis[node] = 1;
    for(auto neighbour:adj[node])
    {
       int neighbourNode = neighbour.first;
       if(!vis[neighbourNode])
       toposort(neighbourNode,adj,vis,st);
    }
    st.push(node);
}

vector<int> shortestDistancesFromSrc(int src,int v,vector<pair<int,int>> adj[])
{
    vector<int> dist(v,INT_MAX);
    dist[src] = 0;
    stack<int> st;
    int vis[v] = {0};
    for(int i=0; i<v; i++)
    {
        if(!vis[i])
        toposort(i,adj,vis,st);
    }

    while(!st.empty())
    {
        int node = st.top();
        st.pop();
        int distance = dist[node];

        if(distance != INT_MAX)
        {

             for(auto neighbour: adj[node])
            {
            int nod = neighbour.first;
            int weight = neighbour.second;

            if(distance + weight < dist[nod])
            dist[nod] = distance + weight;
            }

        }
    }

    return dist;
}

int main()
{
    int v = 7;
    vector<pair<int, int>> adj[v];

    // Adding edges
    adj[0].push_back({1, 2});
   
    adj[1].push_back({3, 1});

    adj[2].push_back({3, 3});

    // adj[3] has no outgoing edges

    adj[4].push_back({0, 3});
    adj[4].push_back({2, 1});

    adj[5].push_back({4, 1});
    

    adj[6].push_back({4, 2});
    adj[6].push_back({5, 3});


    vector<int> ans = shortestDistancesFromSrc(6,7,adj);
    for(int num:ans) cout<<num<<" ";

    return 0;
}