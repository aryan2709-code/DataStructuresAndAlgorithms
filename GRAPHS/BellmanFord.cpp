
/*
Bellman-Ford algorithm is another technique for finding the shortest path in a directed graph.
It is a single source shortest path algorithm
If the graph is undirected, we treat each edge as two directed edges:
For example, an edge like 1 --- 5 will be represented as both 1 -> 5 and 5 -> 1.

For a graph with 'n' nodes, we perform 'n - 1' iterations of edge relaxation.
Why n - 1 iterations? — Because, in the worst case, the shortest path from the source to any other node can have at most n - 1 edges.

To detect a negative weight cycle, we perform one extra (i.e., the nth) iteration.
If during this iteration, any distance still gets updated, then the graph contains a negative weight cycle.
*/


#include<iostream>
#include<vector>
using namespace std;

vector<int> bellmanFordAlgo(int v,int src, vector<vector<int>>& edges)
{
    vector<int> dist(v,1e9); // distance array
    dist[src] = 0;
    // n-1 iterations : v-1 iterations as there are v number of nodes here
    for(int iteration = 1; iteration <= v-1; iteration++)
    {
        for(auto it:edges)
        {
            int node1 = it[0];
            int node2 = it[1];
            int edgeWeight = it[2];

            if(dist[node1] != 1e9 && dist[node1] + edgeWeight < dist[node2])
            {
                dist[node2] = dist[node1] + edgeWeight;
            }
        }
    }

    // The nth iteration, if there are any updates, then there is a negative weight cycle
    for(auto it:edges)
    {
        int node1 = it[0];
        int node2 = it[1];
        int edgeWeight = it[2];

        if(dist[node1] + edgeWeight < dist[node2] )
        {
            return {-1};
        }
    }

    return dist;

}

void printArray(vector<int>& arr)
{
    for(int num : arr)
    cout << num << " ";

    cout << "\n";
}

int main()
{
    vector<vector<int>> edges = {
    {0, 1, -1},
    {0, 2, 4},
    {1, 2, 3},
    {1, 3, 2},
    {1, 4, 2},
    {3, 2, 5},
    {3, 1, 1},
    {4, 3, -3}
};

vector<int> dist = bellmanFordAlgo(5,0,edges);
vector<int> dist1 = bellmanFordAlgo(5,1,edges);
printArray(dist);
printArray(dist1); 
return 0;
}