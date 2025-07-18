#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<int> dijkstra(int v,vector<vector<int>> adj[],int src)
{
    set<pair<int,int>> st;
    vector<int> dist(v,1e9);

    dist[src] = 0;
    st.insert({0,src});

    while(!st.empty())
    {
        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;
        st.erase(it);

        for(auto it:adj[node])
        {
            int edgeWeight = it[1];
            int adjNode = it[0];

            if(dis + edgeWeight < dist[adjNode])
            {
                if(dist[adjNode] != 1e9) // Someone has reached the adjacent node before, but since we have reache dtjere with a better distance , this entry due to the earlier arrival at the adjNode is not useful and can be removed to safe redundant iterations
                st.erase({dist[adjNode],adjNode});

                dist[adjNode] = dis + edgeWeight;
                st.insert({dist[adjNode],adjNode});
            }
        }
    }
    return dist;
}

int main()
{
     int V = 5;
    vector<vector<int>> adj[V];

    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[0].push_back({3, 7});

    adj[1].push_back({2, 1});

    adj[2].push_back({3, 3});
    adj[2].push_back({4, 5});

      vector<int> distances =  dijkstra(V, adj, 0);
      for(auto it:distances) cout<<it<<" ";
      return 0;
}