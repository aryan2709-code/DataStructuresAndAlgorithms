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

void recursiveInorder(Node* root)
{
    if(root == NULL)
    return;

    recursiveInorder(root->left);
    cout << root->val << " ";
    recursiveInorder(root->right);
}

void iterativeInorder(Node* root)
{
    Node* node = root;
    stack<Node*> st;
    while(node != NULL || !st.empty())
    {
        if(node != NULL)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            auto it = st.top();
            st.pop();
            cout << it->val << " ";
            node = it->right;
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
    iterativeInorder(root);
}

