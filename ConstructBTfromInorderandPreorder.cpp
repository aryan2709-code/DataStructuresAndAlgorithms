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

void printTree(Node* root, int space = 0, int indent = 5) {
    if (root == NULL) return;

    space += indent;

    printTree(root->right, space);
    cout << endl;
    for (int i = indent; i < space; i++) cout << " ";
    cout << root->val << "\n";
    printTree(root->left, space);
}

Node* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int,int> inMap)
{
    if(preStart > preEnd || inStart > inEnd)
    return NULL;

    Node* root = new Node(preorder[preStart]);
    int inRoot = inMap[root->val];
    int numsLeft = inRoot-inStart;

    root->left = buildTree(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inRoot-1,inMap);
    root->right = buildTree(preorder, preStart+numsLeft+1,preEnd,inorder,inRoot+1,inEnd,inMap);

    return root;
}

Node* TreeFromInorderandPreorder(vector<int>& preorder,vector<int>& inorder)
{
    unordered_map<int,int> inMap;
    for(int i=0; i<inorder.size();i++)
    inMap[inorder[i]] = i;

    Node* root = buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inMap);
    return root;
}

int main()
{
    vector<int> preorder = {10,20,40,50,30,60};
    vector<int> inorder = {40,20,50,10,60,30};

    Node* tree = TreeFromInorderandPreorder(preorder,inorder);
    printTree(tree);
    return 0;
}

