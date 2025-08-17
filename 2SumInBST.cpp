#include<iostream>
#include<stack>
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

class BSTIterator{
 private:
 stack<Node*> st;
 bool reverse = true; // reverse true -> run reverse inorder
 void pushAll(Node* node)
 {
    for( ;node!=NULL; )
    {
        st.push(node);
        if(reverse == true) // reverse inorder -> right root left
        {
             node = node->right;
        }
        else // inorder -> left root right
        {
            node = node->left;
        }
    }
 }
 public:
 BSTIterator(Node* root, bool isReverse)
 {
    reverse = isReverse;
    pushAll(root);
 }
 // has next function, in reverse inorder it means the next smaller element in the inorder, in inorder it just means the next element in the 
 // inorder sequence
 bool hasNext()
 {
    return !st.empty();
 }

 int next()
 {
    Node* tempNode = st.top();
    st.pop();
    if(reverse) // right and root done, time for left
    pushAll(tempNode->left);
    else         // left and root done, time for right portion of the tree
    pushAll(tempNode->right);

    return tempNode->val;
 }

};

class Solution{
public:
bool findTarget(Node* root, int k)
{
    if(root == NULL)
    return false;

    BSTIterator l(root,false);
    BSTIterator r(root,true);

    int i = l.next();
    int j = r.next();
    while(i < j)
    {
        if(i + j == k)
        return true;
        else if(i + j < k)
        i = l.next();
        else
        j = r.next();
    }
    return false;
}
};