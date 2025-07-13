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

Node* inorderSuccessor(Node* root, Node* p)
{
    Node* successor = NULL;
    while(root != NULL)
    {
        if(root->val > p->val) //possible answer
        {
           successor = root;
           root = root->left; // look for a node with even smaller value
        }
        else
        {
            root = root->right;
        }
    }
    return successor;
}

Node* inorderPredecessor(Node* root, Node* p)
{
    Node* predecessor = NULL;
    while(root != NULL)
    {
        if(root->val < p->val) //possible answer
        {
            predecessor = root;
            root = root->right; // Look for a node with larger value
        }
        else
        {
            root = root->left;
        }
    }
    return predecessor;
}

int main()
{
    Node* root = new Node(64);

    root->left = new Node(32);
    root->right = new Node(96);

    root->left->left = new Node(16);
    root->left->right = new Node(48);
    root->right->left = new Node(80);
    root->right->right = new Node(112);

    root->left->left->left = new Node(8);
    root->left->left->right = new Node(24);
    root->left->right->left = new Node(40);
    root->left->right->right = new Node(56);
    root->right->left->left = new Node(72);
    root->right->left->right = new Node(88);
    Node* node = root->right->right->left = new Node(104);
    root->right->right->right = new Node(120);

    root->left->left->left->left = new Node(4);
    root->left->left->left->right = new Node(12);
    root->left->right->right->right = new Node(60);
    root->right->right->left->right = new Node(108);

    Node* inorderPredecess = inorderPredecessor(root,node);
    Node* inorderSuccess = inorderSuccessor(root,node);

    cout << "the predecessor is "<<inorderPredecess->val<<" and the successor is "<<inorderSuccess->val<<endl;
    return 0;
}