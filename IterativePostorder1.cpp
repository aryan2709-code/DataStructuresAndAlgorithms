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

void recursivePostorder(Node* root)
{
    if(root == NULL)
    return;

    recursivePostorder(root->left);
    recursivePostorder(root->right);
    cout << root->val << " ";
}

void iterativePostorder(Node* root)
{
    stack<Node*> st1;
    st1.push(root);
    stack<Node*> st2;
    while(!st1.empty())
    {
        Node* top = st1.top();
        st1.pop();
        st2.push(top);
        if(top->left)
        st1.push(top->left);
        if(top->right)
        st1.push(top->right);
    }
    while(!st2.empty())
    {
        cout << st2.top()->val << " ";
        st2.pop();
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

    recursivePostorder(root);
    cout << endl;
    iterativePostorder(root);
    return 0;
}