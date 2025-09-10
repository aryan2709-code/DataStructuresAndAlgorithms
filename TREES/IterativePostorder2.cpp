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

void recursivePostorder(Node* root)
{
    if(!root) return;
    recursivePostorder(root->left);
    recursivePostorder(root->right);
    cout << root->val << " ";
}

void iterativePostorder(Node* root)
{
    Node* curr = root;
    Node* temp = NULL;
    stack<Node*> st;
    while(curr != NULL || !st.empty())
    {
        if(curr != NULL)
        {
            st.push(curr); //push root and go left
            curr = curr->left; // keep diving into the left
        }
        else
        {
           temp = st.top()->right; // check right child of the top
           if(temp == NULL) // means left and right done , process the top
           {
             temp = st.top(); 
             st.pop();
             cout << temp->val << " "; //processing the top

               // backtrack upwards : 
               // if coming from right child, parent is also ready
               // parent's left is done , right is just now done , so now its parent's turn
             while(!st.empty() && temp == st.top()->right)
             {
                temp = st.top();
                st.pop();
                cout << temp->val << " ";
             }
           }
           else
           {
            curr = temp; // if right child exists -> go process it
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

    recursivePostorder(root);
    cout << endl;
    iterativePostorder(root);
    return 0;
}

