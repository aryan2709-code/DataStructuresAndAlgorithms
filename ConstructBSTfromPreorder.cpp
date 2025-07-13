#include<iostream>
#include<vector>
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

void printTree(Node* root, int space = 0, int indent = 5) {
    if (root == NULL) return;

    space += indent;

    printTree(root->right, space);
    cout << endl;
    for (int i = indent; i < space; i++) cout << " ";
    cout << root->val << "\n";
    printTree(root->left, space);
}
Node* build(vector<int>& preorder,int& i,int bound)
{
    // Base case : If the current element is out of bound or the index i is out of bounds of the array, we return a null
    if(i == preorder.size() || preorder[i] > bound)
    {
        return NULL;
    }
    Node* root = new Node(preorder[i++]); // i updated to the next index
    root->left = build(preorder,i,root->val);
    root->right = build(preorder,i,bound);
    return root;
}
Node* BSTfromPreorder(vector<int>& preorder)
{
    int i = 0;
    return build(preorder,i,INT_MAX);
}

int main()
{
    vector<int> preorder = {50, 30, 20, 40, 70, 60, 80};
    Node* root = BSTfromPreorder(preorder);
    cout << "The required tree is : \n\n\n\n";
    printTree(root);
    return 0;
}