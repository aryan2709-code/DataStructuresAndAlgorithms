#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

vector<vector<int>> verticalOrderTraversal(Node* root)
{
  map<int,map<int,multiset<int>>> nodes; // vertical -> level -> {multiple nodes}
  queue<pair<Node*,pair<int,int>>> q;    // Node , {vertical , level}
  q.push({root, {0,0}});
  while(!q.empty())
  {
    auto top = q.front();
    q.pop();
    Node* node = top.first;
    int vertical = top.second.first;
    int level = top.second.second;

    nodes[vertical][level].insert(node->data);
    if(node->left)
    {
        q.push({node->left,{vertical-1,level+1}});
    }
    if(node->right)
    {
        q.push({node->right,{vertical+1,level+1}});
    }
  }
  vector<vector<int>> ans;
  for(auto p:nodes)
  {
    vector<int> col;
    for(auto q:p.second)
    {
        col.insert(col.end(),q.second.begin(),q.second.end());
    }
    ans.push_back(col);
  }
return ans;
}
void printArray(vector<int>& arr)
{
    for(int number:arr)
    cout << number << " ";

    cout << endl;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->left = new Node(5);
    root->left->left->right = new Node(6);
    root->left->left->right->right = new Node(7);

    vector<vector<int>> ans = verticalOrderTraversal(root);
    for(auto vec : ans)
    printArray(vec);

    return 0;
}
