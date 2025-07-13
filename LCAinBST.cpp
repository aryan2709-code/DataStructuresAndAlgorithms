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

Node* lca(Node* root,Node* p,Node* q)
{
    if(root == NULL)
    return NULL;

    int curr = root->val;
    if(curr < p->val && curr < q->val)
    {
        return lca(root->right,p,q);
    }
    else if(curr > p->val && curr > q->val)
    {
        return lca(root->left,p,q);
    }
    else // current node's val is equal to one of p or q or both lie on different sides of the current node
    {
    return root;
    }
}

int main()
{
    Node* root = new Node(64);

    root->left = new Node(32);
    root->right = new Node(96);

    root->left->left = new Node(16);
    root->left->right = new Node(48);
    root->right->left = new Node(80);
    root->right->right = new Node(112);

    root->left->left->left = new Node(8);
    root->left->left->right = new Node(24);
    Node* q = root->left->right->left = new Node(40);
    root->left->right->right = new Node(56);
    root->right->left->left = new Node(72);
    root->right->left->right = new Node(88);
    root->right->right->left = new Node(104);
    root->right->right->right = new Node(120);

    root->left->left->left->left = new Node(4);
    Node* p = root->left->left->left->right = new Node(12);
    root->left->right->right->right = new Node(60);
    root->right->right->left->right = new Node(108);

    Node* lowestcommon = lca(root,p,q);
    cout << "The lowest common ancestor is "<<lowestcommon->val<<endl;
    return 0;
}