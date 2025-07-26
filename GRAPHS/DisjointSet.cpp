#include<iostream>
#include<vector>
using namespace std;

// This data structure is used for dynamic graphs 
class DisjointSet
{
public:
vector<int> rank,parent,size;
DisjointSet(int n) // n is the number of nodes in the graph
{
    rank.resize(n+1,0);
    parent.resize(n+1,0);
    for(int i=0;i<=n;i++)
    parent[i] = i;
    size.resize(n+1,1);
}

int findParent(int node)
{
    if(parent[node] == node)
    return node;

   return parent[node] = findParent(parent[node]);
}

void unionByRank(int u, int v)
{
    //Find the ultimate parents for both the nodes
    int ulp_u = findParent(u);
    int ulp_v = findParent(v);

    if(ulp_u == ulp_v) //Already in the same component
    return; 

    if(rank[ulp_u] < rank[ulp_v]) //Connect the lower rank component to the larger rank component
    {
        parent[ulp_u] = ulp_v;
    }
    else if(rank[ulp_v] < rank[ulp_u])
    {
        parent[ulp_v] = ulp_u;
    }
    else
    {
        parent[ulp_v] = ulp_u;
        rank[ulp_u]++;
    }
}

void unionBySize(int u, int v)
{
// Find the ultimate parents for both the nodes
int ulp_u = findParent(u);
int ulp_v = findParent(v);
if(ulp_u == ulp_v)
return;

if(size[ulp_u] < size[ulp_v])
{
    parent[ulp_u] = ulp_v;
    size[ulp_v] += size[ulp_u];
}
else if(size[ulp_v] <= size[ulp_u])
{
    parent[ulp_v] = ulp_u;
    size[ulp_u] += size[ulp_v];
}
}
};

int main()
{
    DisjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);

    // If 3 and 7 belong to the same component or not
    if(ds.findParent(3) == ds.findParent(7))
    {
        cout << "same \n";
    }
    else
    {
         cout << "not same \n";
    }

    ds.unionByRank(3,7);
    if(ds.findParent(3) == ds.findParent(7))
    {
        cout << "same \n";
    }
    else
    {
         cout << "not same \n";
    }

    return 0;
}