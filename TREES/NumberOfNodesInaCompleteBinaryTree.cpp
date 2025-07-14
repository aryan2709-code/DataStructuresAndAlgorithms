#include<iostream>
using namespace std;
class Node{
public:
int data;
Node* left;
Node* right;
Node(int val)
{
    data = val;
    left = right = NULL;
}
};

int findLeftHeight(Node* root)
{
    int hght = 0;
    while(root)
    {
        hght++;
        root = root->left; 
    }
    return hght;
}

int findRightHeight(Node* root)
{
    int hght = 0;
    while(root)
    {
        hght++;
        root = root->right;
    }
    return hght;
}

int countNodes(Node* root)
{
    if(root == NULL)
    return 0;

    int lh = findLeftHeight(root);
    int rh = findRightHeight(root);

    if(lh == rh)
    return (1 << lh) - 1;
    
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    cout << "The Number of nodes in this complete binary tree is : "<<countNodes(root)<<endl;
    return 0;
}