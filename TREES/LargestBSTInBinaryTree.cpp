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

class NodeValue{
    public:
    int size;
    int maxval;
    int minval;
    NodeValue(int size, int maxval, int minval)
    {
        this->size = size;
        this->maxval = maxval;
        this->minval = minval;
    }
};

NodeValue largestBSThelper(Node* root) // Postorder traversal because i need both the left as well as the right info before processing the current node
{
      if(root == NULL)
      return NodeValue(0,INT_MIN,INT_MAX);

      // Get values from the left and the right subtree
      auto left = largestBSThelper(root->left);
      auto right = largestBSThelper(root->right);

      // Compare these values with the current root's value
      if(root->val > left.maxval &&  root->val < right.minval)
      return NodeValue( left.size + right.size + 1, max(root->val,right.maxval) , min(root->val,left.minval) );

       
      // IF THE CURRENT NODE CAN NOT BE A PART OF A VALID BST WITH LEFT AND RIGHT SUBTREES
      return NodeValue(max(left.size,right.size),INT_MAX,INT_MIN);
}

int largestBSTSubtree(Node* root)
{
    return largestBSThelper(root).size;
}