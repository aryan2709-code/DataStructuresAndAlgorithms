#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int dat)
    {
        data = dat;
        left = right = NULL;
    }
};

bool isLeafNode(Node* node)
{
  if(node->left == NULL && node->right == NULL)
  return true;

  return false;
}

void addLeftBoundaryTraversal(Node* root,vector<int>& res)
{
Node* curr = root->left;
while(curr)
{
    if(!isLeafNode(curr)) 
    res.push_back(curr->data);
    if(curr->left)
    curr = curr->left;
    else
    curr = curr->right;
}
}

void addRightBoundaryTraversal(Node* root,vector<int>& res)
{
  Node* curr = root->right;
  vector<int> temp;
  while(curr)
  {
    if(!isLeafNode(curr))
    temp.push_back(curr->data);
    if(curr->right)
    curr = curr->right;
    else
    curr = curr->left;
  }
  for(int i = temp.size() - 1; i>=0; i--)
  {
    res.push_back(temp[i]);
  }
}

void addLeaves(Node* root,vector<int>& res)
{
  if(isLeafNode(root))
  {
    res.push_back(root->data);
    return;
  }
  if(root->left)
  addLeaves(root->left,res);
  if(root->right)
  addLeaves(root->right,res);
}

vector<int> printBoundary(Node* root)
{
  vector<int> res;
  if(!root)
  return res;
  if(!isLeafNode(root))
  res.push_back(root->data);
  addLeftBoundaryTraversal(root,res);
  addLeaves(root,res);
  addRightBoundaryTraversal(root,res);
  return res;
}

void printArray(vector<int>& arr)
{
    for(int number:arr)
    cout << number << " ";

    cout <<endl;
}

int main()
{
  vector<int> ans;
  Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->left = new Node(5);
    root->left->left->right = new Node(6);
    root->left->left->right->right = new Node(7);
    ans = printBoundary(root);
    printArray(ans);
    return 0;
}