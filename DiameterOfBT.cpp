#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node()
    {
        data = 0;
        left = right = NULL;
    }
    Node(int data)
    {
        data = data;
        left = NULL;
        right = NULL;
    }
};
int findMax(Node* node, int& maxi)
{
    if(node == NULL)
    return 0;

    int lh = findMax(node->left,maxi);
    int rh = findMax(node->right,maxi);

    maxi = max(maxi, lh + rh + 1);
    return 1 + max(lh,rh);
}

int main()
{
     Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->left = new Node(5);
    root->left->left->right = new Node(6);
    root->left->left->right->right = new Node(7);

    int maxi = 0;
    findMax(root,maxi);
    cout << "The diameter is : "<<maxi;
    return 0;
}