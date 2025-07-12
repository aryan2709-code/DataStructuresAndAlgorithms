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
        right = left = NULL;
    }
};

void recursiveInorder(Node* root)
{
    if(root == NULL)
    return;

    recursiveInorder(root->left);
    cout << root->val << " ";
    recursiveInorder(root->right);
}

void MorrisInorder(Node* root)
{
    Node* curr = root;
    while(curr != NULL)
    {
        if(curr->left == NULL)
        {
            cout << curr->val << " ";
            curr = curr->right;
        }
        else // left child of the current node exists
        {
          Node* prev = curr->left;
          while(prev->right && prev->right != curr)
          prev = prev->right;

          if(prev->right == NULL) // first time visit
          {
            prev->right = curr;
            curr = curr->left;
          }
          else // right most node of the left subtree already points to the current node, this signifies the left part is already traversed
          {
             prev->right == NULL;
             cout << curr->val << " ";
             curr = curr->right;
          }
        }
    }
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    recursiveInorder(root);
    cout << "\n";
    MorrisInorder(root);
    return 0;
}