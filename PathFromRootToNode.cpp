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

bool getPath(Node* root,vector<int>& arr,int x)
{
if(!root)
return false;

arr.push_back(root->data);
if(root->data == x)
return true;

if(getPath(root->left,arr,x) || getPath(root->right,arr,x))
return true;

// Process the current node, if neither of left or right returns a true , return false,but before doing that , pop back this node from the arr
arr.pop_back();
return false;
}

vector<int> solve(Node* node , int Val)
{
    vector<int> arr;
    if(node == NULL)
    return arr;
    getPath(node,arr,Val);
    return arr;
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
    vector<int> ans = solve(root,7);
    printArray(ans);
    return 0;
}