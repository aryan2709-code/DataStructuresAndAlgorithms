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
Node* LCA(Node* root,Node* p,Node* q)
{
    if(root == NULL || root == p || root == q)
    return root;

    Node* left = LCA(root->left,p,q);
    Node* right = LCA(root->right,p,q);

    if(left == NULL)
    return right;
    else if(right == NULL)
    return left;
    else //both left and right are not null, we found our result
    return root;
}

int main()
{
Node* p;
Node* q;
Node* root = new Node(1);
root->left = new Node(2);
root->right = new Node(3);
root->left->left = new Node(4);
p = root->left->left->left = new Node(5);
root->left->left->right = new Node(6);
q = root->left->left->right->right = new Node(7);
Node* lca = LCA(root,p,q);
cout << "The Lowest common ancestor is "<< lca->val<<endl;
return 0;
}

