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
void changeTree(Node* root)
{
    if(root == NULL)
    return;

    int child = 0;
    if(root->left)
    child += root->left->val;
    if(root->right)
    child += root->right->val;

    if(child >= root->val)
    root->val = child;
    else
    {
        if(root->left)
        root->left->val = child;
        if(root->right)
        root->right->val = child;
    }

    changeTree(root->left);
    changeTree(root->right);


    int tot = 0;
    if(root->left)
    tot += root->left->val;
    if(root->right)
    tot += root->right->val;

    if(root->left || root->right)
    root->val = tot;

}
void printTree(Node* root, int space = 0, int indent = 5) {
    if (root == NULL) return;

    space += indent;

    printTree(root->right, space);
    cout << endl;
    for (int i = indent; i < space; i++) cout << " ";
    cout << root->val << "\n";
    printTree(root->left, space);
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
    changeTree(root);
    cout << "Tree Printed Sideways : ";
    printTree(root);
    return 0;
}