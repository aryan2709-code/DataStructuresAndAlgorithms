#include<iostream>
#include<climits>
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

bool validateBST(Node* root, long long minval, long long maxval)
{
    if(root == NULL)
    return true;

    if(root->val >= maxval || root->val <= minval)
    return false;

    bool left = validateBST(root->left,minval,root->val);
    bool right= validateBST(root->right,root->val,maxval);

    return left && right;
}

int main()
{
    // tree 1 : BST
    Node* root1 = new Node(8);
root1->left = new Node(4);
root1->right = new Node(12);
root1->left->left = new Node(2);
root1->left->right = new Node(6);
root1->right->left = new Node(10);
root1->right->right = new Node(14);
if(validateBST(root1,LLONG_MIN,LLONG_MAX)) cout<<"Tree 1 is a BST"<<endl;
else cout << "Tree 1 is not a BST"<<endl;
// tree 2 : not a bst

Node* root2 = new Node(1);
root2->left = new Node(2);
root2->right = new Node(3);
root2->left->left = new Node(4);
root2->left->right = new Node(5);
if(validateBST(root2,LLONG_MIN,LLONG_MAX)) cout<<"Tree 2 is a BST"<<endl;
else cout << "Tree 2 is not a BST"<<endl;
return 0;
}
