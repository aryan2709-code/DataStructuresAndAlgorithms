#include<iostream>
#include<bits/stdc++.h>
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

void printTree(Node* root,int space=0,int indent=5)
{
if (root == NULL) return;

    space += indent;

    printTree(root->right, space);
    cout << endl;
    for (int i = indent; i < space; i++) cout << " ";
    cout << root->val << "\n";
    printTree(root->left, space);
}

string serialize(Node* root) // Using a level order traversal to serialise or encode the tree
{
    if(!root)
    return "";

    string s = "";
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* currNode = q.front();
        q.pop();

        if(!currNode)
        s.append("#,");
        else
        s.append(to_string(currNode->val) + ",");

        if(currNode != NULL)
        {
            q.push(currNode->left);
            q.push(currNode->right);
        }
    }
    return s;
}

Node* deserialize(string data)
{
    if(data.size() == 0)
    return NULL;

    stringstream s(data);
    string str;
    getline(s,str,',');

    Node* root = new Node(stoi(str));
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* node = q.front();
        q.pop();

        getline(s,str,',');
        if(str == "#")
        node->left = NULL;
        else
        {
            Node* leftNode = new Node(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }

        getline(s,str,',');
        if(str == "#")
        node->right = NULL;
        else
        {
            Node* rightNode = new Node(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
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
    printTree(root);
    string str = serialize(root);
    Node* root2 = deserialize(str);
    printTree(root2);
    return 0;
}