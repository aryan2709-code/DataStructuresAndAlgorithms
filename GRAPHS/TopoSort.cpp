#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution{
private:
void topodfs(int node,stack<int>& st,vector<int> adj[],int vis[])
{
    vis[node] = 1;
    for(int it:adj[node])
    {
        if(!vis[it])
        {
            topodfs(it,st,adj,vis);
        }
    }
    // After dfs is complete push it in the stack
    st.push(node);
}
public:
void printArray(vector<int>& arr)
{
    for(int num:arr) cout << num << " ";
    cout << "\n";
}
vector<int> topoSort(int v,vector<int> adj[])
{
  int vis[v] = {0};
  stack<int> st;
  for(int i=0; i<v; i++)
  {
    if(!vis[i])
    {
        topodfs(i,st,adj,vis);
    }
  }
  vector<int> topoSequence;
  while(!st.empty())
  {
    topoSequence.push_back(st.top());
    st.pop();
  }
  return topoSequence;
}
};

int main()
{
Solution s;
vector<int> adj[4];
adj[0] = {1, 2};
adj[1] = {3};
adj[2] = {3};
adj[3] = {};

vector<int> ans = s.topoSort(4,adj);
s.printArray(ans);
return 0;
}
