#include<iostream>
using namespace std;
class Node{
public:
int val;
Node* left;
Node* right;
Node(int val)
{
    this->val = val;
    left = right = NULL;
}
};

class Solution{
private:
Node* first;
Node* last;
Node* prev;
Node* middle;
private:
void inorder(Node* root)
{
if(root == NULL)
return;

inorder(root->left);

// The main logic
if(prev != NULL && (root->val < prev->val)) // there is a violation
{
    // If this is the first violation, mark these two nodes as the first and the middle node
    if(first == NULL)
    {
        first = prev;
        middle = root;
    }
    else // if this is the second violation mark this node as the last
    last = root;

}
// Mark this current node as the previous for the next node in the sequence
prev = root;

inorder(root->right);
}
public:
void recoverTree(Node* root)
{
    first = middle = last = NULL;
    prev = new Node(INT_MIN);
    inorder(root);
    if(first && last) swap(first->val,last->val);
    else if(first && middle) swap(first->val,middle->val);
}
};