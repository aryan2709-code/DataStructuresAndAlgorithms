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
using pni = pair<Node*,int>; 

void allTraversalsInOne(Node* root,vector<int>& preorder,vector<int>& inorder,vector<int>& postorder)
{
    stack<pni> st;
    st.push({root,1});

    while(!st.empty())
    {
        auto it = st.top();
        st.pop();

        if(it.second == 1) // part of preorder traversal,increment 1 to 2 , push left
        {
            preorder.push_back(it.first->val);
            it.second++;
            st.push(it);

            if(it.first->left != NULL)
            {
                st.push({it.first->left,1});
            }
        }
        else if(it.second == 2) // part of inorder traversal, increment 2 to 3, push right
        {
          inorder.push_back(it.first->val);
          it.second++;
          st.push(it);

          if(it.first->right != NULL)
          {
            st.push({it.first->right,1});
          }
        }
        else
        {
            postorder.push_back(it.first->val);
        }
    }
}
void printarray(vector<int>& arr)
{
    for(int num: arr)
    cout << num << " ";

    cout << endl;
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

    vector<int> preorder,inorder,postorder;
    allTraversalsInOne(root,preorder,inorder,postorder);
    cout<<"Preorder : "; 
    printarray(preorder);
    cout<<"Inorder: ";
    printarray(inorder);
    cout<<"Postorder: ";
    printarray(postorder);
    return 0;
}