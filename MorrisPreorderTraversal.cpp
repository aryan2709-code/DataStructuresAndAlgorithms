#include<iostream>
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

void morrisPreorder(Node* root)
{
    Node* curr = root;
    while(curr != NULL)
    {
        if(curr->left == NULL)
        {
            cout << curr->val << " ";
            curr = curr->right;
        }
        else
        {
            Node* prev = curr->left;
            while(prev->right && prev->right != curr)
            prev = prev->right;

            if(prev->right == NULL)
            {
                prev->right = curr;
                cout << curr->val << " ";
                curr = curr->left; // After making sure, there is a way to come back , move to left
            }
            else
            {
                prev->right = NULL;
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
    recursivePreorder(root);
    cout << "\n";
    morrisPreorder(root);
    return 0;
}