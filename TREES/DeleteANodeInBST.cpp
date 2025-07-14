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

Node* findLastRight(Node* root)
{
    if(root->right == NULL)
    return root;

    return findLastRight(root->right);
}

Node* helper(Node* root)
{
    if(root->left == NULL)
    return root->right;
    else if(root->right == NULL)
    return root->left;
   
    Node* right = root->right;
    Node* rightMostOfLeft = findLastRight(root->left);
    rightMostOfLeft->right = right;
    return root->left;
}

Node* deleteNode(Node* root,int key)
{
    if(root == NULL)
    return NULL;

    if(root->val == key)
    return helper(root);

    Node* dummy = root;
    while(root != NULL)
    {
        if(key < root->val)
        {
            if(root->left != NULL && root->left->val == key)
            {
                root->left = helper(root->left);
                break;
            }
            else
            root = root->left;
        }
        else
        {
            if(root->right != NULL && root->right->val == key)
            {
                root->right = helper(root->right);
                break;
            }
            else
            root = root->right;
        }
    }
    return dummy;
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
    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(12);

    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);
    printTree(root);
    cout << "\n\n\n\n";
    deleteNode(root,6);
    printTree(root);
    return 0;
}
