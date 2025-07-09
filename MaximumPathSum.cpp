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
        this->data = data;
        left = NULL;
        right = NULL;
    }
};



int maxPathDown(Node* node,int& maxi)
{
    if(node == NULL)
    return 0;

    int left = max(0 , maxPathDown(node->left,maxi));
    int right = max(0,maxPathDown(node->right,maxi));

    maxi = max(maxi,left+right+node->data);

    return max(left,right) + node->data;
}

int maxPathSum(Node* root , int& maxi)
{
    maxPathDown(root,maxi);
    return maxi;
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
    cout << "The maximum Path Sum is : "<<maxPathSum(root,maxi);
    return 0;
}