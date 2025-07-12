// This program depicts three methods of converting a binary tree into linked list following the preorder traversal, by rearranging the given tree itself
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

void printTree(Node* root,int space=0,int indent=5)
{
    if (root == NULL) return;

    space += indent;

    printTree(root->right, space);
    cout << endl;
    for (int i = indent; i < space; i++) cout << " ";
    cout << root->val << "\n";
    printTree(root->left, space);
}

void recursiveFlatten(Node* node,Node*& prev)
{
    if(node == NULL)
    return;

    recursiveFlatten(node->right,prev);
    recursiveFlatten(node->left,prev);

    node->right = prev;
    node->left  = NULL;

    prev = node;
}

void iterativeStackFlatten(Node* root)
{
stack<Node*> st;
st.push(root);
while(!st.empty())
{
    Node* curr = st.top();
    st.pop();

    if(curr->right)
    st.push(curr->right);
    if(curr->left)
    st.push(curr->left);
    if(!st.empty())
    curr->right = st.top();

    curr->left = NULL;
}
}

void morrisFlatten(Node* root)
{
    Node* curr = root;
    while(curr != NULL)
    {
        if(curr->left != NULL)
        {
            Node* prev = curr->left;
            while(prev->right)
            prev = prev->right;

            prev->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}


int main()
{
    // Tree 1:
Node* root1 = new Node(1);
root1->left = new Node(2);
root1->right = new Node(3);
root1->left->left = new Node(4);
root1->left->right = new Node(5);
root1->right->left = new Node(6);
root1->right->right = new Node(7);

// tree 2:
Node* root2 = new Node(1);
root2->left = new Node(2);
root2->left->left = new Node(3);
root2->left->left->left = new Node(4);

// tree 3:
Node* root3 = new Node(10);
root3->left = new Node(5);
root3->left->right = new Node(8);
root3->right = new Node(15);
root3->right->right = new Node(20);

Node* prev = NULL;
recursiveFlatten(root1,prev);
printTree(root1);
cout << "\n\n\n\n";

iterativeStackFlatten(root2);
printTree(root2);
cout << "\n\n\n\n";

morrisFlatten(root3);
printTree(root3);
cout << "\n\n\n\n";

return 0;
}