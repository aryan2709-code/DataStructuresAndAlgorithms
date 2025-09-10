#include<iostream>
#include<stack>
using namespace std;
class Node{
public:
int val;
Node* left;
Node* right;
};

class BSTIterator{
private:
stack<Node*> myStack;
void pushAll(Node* node)
{
    for( ; node != NULL; myStack.push(node),node = node->left); // Push the current element root, and all the lefts to it as long as we not hit null
}
public:
BSTIterator(Node* root)
{
    pushAll(root);
}

// Has Next Function - whether the next element in the inorder sequence exists or not 
bool hasNext()
{
    return !myStack.empty();
}

// next() - return the next number in the inorder sequence
int next()
{
    Node* tempNode = myStack.top();
    myStack.pop();
    pushAll(tempNode->right);
    return tempNode->val;
}
};
