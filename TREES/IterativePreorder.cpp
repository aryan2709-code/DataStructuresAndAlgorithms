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

void recursivePreorder(Node* root)
{
    if(root == NULL)
    return;

    cout << root->val << " ";
    recursivePreorder(root->left);
    recursivePreorder(root->right);
}

void iterativePreorder(Node* root)
{
    stack<Node*> st;
    st.push(root);

    while(!st.empty())
    {
        auto it = st.top();
        st.pop();
        cout << it->val<<" ";

        if(it->right)
        st.push(it->right);

        if(it->left)
        st.push(it->left);
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

    recursivePreorder(root);
    cout << "\n";
    iterativePreorder(root);
    return 0;
}