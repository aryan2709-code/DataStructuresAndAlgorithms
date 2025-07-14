#include<iostream>
using namespace std;
#include<bits/stdc++.h>

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

Node* insertInBST(Node* root,int val)
{
    if(root == NULL)
    return new Node(val);

    Node* curr = root;
    while(true)
    {
        if(val > curr->val)
        {
            if(curr->right)
            curr = curr->right;
            else
            {
                curr->right = new Node(val);
                break;
            }
        }
        else
        {
            if(curr->left)
            curr = curr->left;
            else
            {
                curr->left = new Node(val);
                break;
            }
        }
    }
    return root;
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

    Node* node = insertInBST(root,11);
    printTree(node);
    return 0;
}