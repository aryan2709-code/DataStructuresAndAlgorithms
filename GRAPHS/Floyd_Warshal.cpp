/* 
Floyd-Warshall Algorithm is a dynamic programming-based algorithm used for finding the shortest distances 
between every pair of nodes in a **weighted graph** (can be directed or undirected). It works for both 
positive and **negative** edge weights (as long as there are **no negative weight cycles**).

The algorithm uses an adjacency matrix to store distances.
The core idea is to iterate over each node and try to "improve" the path between every (i, j) pair using this node as an intermediate.
The time complexity is O(n^3), where n is the number of nodes.
It’s best suited for **dense graphs** or when you need all-pairs shortest paths.

Steps:
1. Initialize a `dist[][]` matrix with edge weights.
2. Set `dist[i][i] = 0` for all `i` (distance to itself).
3. For each intermediate node `k`, update `dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])`.

If after running the algorithm, `dist[i][i] < 0` for any `i`, a **negative weight cycle** exists.
*/

#include<iostream>
#include<vector>
using namespace std;

void FloydWarshal(vector<vector<int>>& adjacencyMatrix)
{
    int n = adjacencyMatrix.size(); // The size is the number of nodes in the graph also , 0-based indexing

    // Do, intitial checks , for all self nodes , i.e 0-0 , 1-1 , the adjacency matrix value should be strictly 0.
    for(int i=0; i<n; i++)
    adjacencyMatrix[i][i] = 0;

    for(int node = 0; node<n; node++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                adjacencyMatrix[i][j] = min(adjacencyMatrix[i][j] , (adjacencyMatrix[i][node] + adjacencyMatrix[node][j]));
            }
        }
    }

    // Negative check
    /*
    for(int node = 0; node < n; node++)
    {
    if(adjacencyMatrix[node][node] != 0) 
    {
    // ***** There is a negative weight cycle in the graph ************ //
    }
    }
    */


}

void printMatrix(vector<vector<int>>& matrix)
{
    for(int i=0; i<matrix.size(); i++)
    {
        for(int j=0; j<matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout<<"\n";
    }
}

int main()
{
     const int INF = 1e9;
    vector<vector<int>> adj = {
        {0,   3,   INF, 5},
        {2,   0,   INF, 4},
        {INF, 1,   0,   INF},
        {INF, INF, 2,   0}
    };

    FloydWarshal(adj);
    printMatrix(adj);
    return 0;
}
