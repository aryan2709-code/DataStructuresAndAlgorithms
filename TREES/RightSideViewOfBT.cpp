#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void recursion(Node* root,int level,vector<int>& res)
{
    if(root == NULL)
    return;

    if(level == res.size())
    {
        res.push_back(root->data);
    }

    recursion(root->right,level+1,res);
    recursion(root->left,level+1,res);
}

vector<int> rightView(Node* root)
{
    vector<int> res;
    recursion(root,0,res);
    return res;
}
void printArray(vector<int>& arr)
{
    for(int number:arr)
    cout << number << " ";

    cout << endl;
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
    vector<int> ans = rightView(root);
    printArray(ans);
    return 0;
}

