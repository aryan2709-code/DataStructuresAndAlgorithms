#include<iostream>
#include<queue>
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

int widthOfBinaryTree(Node* root)
{
    if(!root)
    return 0;
    int ans = 0;
    queue<pair<Node*,int>> q; // {Node,index}
    q.push({root,0});
    while(!q.empty())
    {
        int size = q.size();
        int mmin = q.front().second; // To make the index starting from zero
        int first,last;
        for(int i=0; i<size; i++)
        {
            int cur_id = q.front().second - mmin;
            Node* node = q.front().first;
            q.pop();

            if(i == 0) first = cur_id;
            if(i == size-1) last = cur_id;
            if(node->left)
            q.push({node->left,cur_id*2+1});
            if(node->right)
            q.push({node->right,cur_id*2+2});
        }
        ans = max(ans , last-first+1);
    }
    return ans;
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

root->left->left->left = new Node(8);
root->right->right->right = new Node(9);

    cout << "The maximum width of the binary tree is : "<<widthOfBinaryTree(root)<<endl;
    return 0;
}