#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
public:
int val;
Node* left;
Node* right;
Node(int data)
{
    val = data;
    left = right = NULL;
}
};

Node* buildTree(vector<int>& postorder,int postStart,int postEnd,vector<int>& inorder, int inStart, int inEnd, unordered_map<int,int>& inMap)
{
    if(postStart > postEnd || inStart > inEnd)
    return NULL;

    int inRoot = inMap[postorder[postEnd]];
    int leftofinRoot = inRoot - inStart;

    Node* root = new Node(postorder[postEnd]);
    root->left = buildTree(postorder,postStart,postStart+leftofinRoot-1,inorder,inStart,inRoot-1,inMap);
    root->right = buildTree(postorder,postStart+leftofinRoot,postEnd-1,inorder,inRoot+1,inEnd,inMap);

    return root;
}

Node* TreeFromInorderAndPostorder(vector<int>& postorder,vector<int>& inorder)
{
    unordered_map<int,int> inMap;
    for(int i=0;i<inorder.size();i++)
    inMap[inorder[i]] = i;
    Node* tree = buildTree(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,inMap);
    return tree;
}

void printTree(Node* root, int space = 0, int indent = 5) {
    if (root == NULL) return;

    space += indent;

    printTree(root->right, space);
    cout << endl;
    for (int i = indent; i < space; i++) cout << " ";
    cout << root->val << "\n";
    printTree(root->left, space);
}

int main()
{
     vector<int> postorder = {40,50,20,60,30,10};
    vector<int> inorder = {40,20,50,10,60,30};

    Node* tree = TreeFromInorderAndPostorder(postorder,inorder);
    printTree(tree);
    return 0;
}