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
void inorderTraversal(Node* root,int& ans,int k)
{
    int count = 0;
    stack<Node*> st;
    Node* node = root;
    while(node != NULL || !st.empty())
    {
        if(node != NULL)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            // Take out the top element of the stack and print it
            Node* top = st.top();
            st.pop();
            count++;
            if(count == k)
            {
                ans = top->val;
                break;
            }
            node = top->right;
        }
    }
}

int kthSmallest(Node* root,int k)
{
    int ans = 0;
    inorderTraversal(root,ans,k);
    return ans;
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
    cout << kthSmallest(root,7);
    return 0;
}