#include<iostream>
#include<unordered_map>
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

void markParents(Node* root,unordered_map<Node* , Node*>& parentTrack)
{
   queue<Node*> q;
   q.push(root);
   while(!q.empty())
   {
    Node* node = q.front();
    q.pop();
    if(node->left)
    {
        parentTrack[node->left] = node;
        q.push(node->left);
    }
    if(node->right)
    {
        parentTrack[node->right] = node;
        q.push(node->right);
    }
   }
}

vector<int> NodesAtDistanceK(Node* root , Node* target , int k)
{
    unordered_map<Node* , Node*> parent_track;
    markParents(root,parent_track);
    unordered_map<Node*,bool> visited;
    queue<Node*> q;
    q.push(target);
    visited[target] = true;
    int level = 0;
    while(!q.empty())
    {
        int size = q.size();
        if(level++ == k)
        break;

        for(int i=0;i<size;i++)
        {
            Node* curr = q.front();
            q.pop();

            if(curr->left && !visited[curr->left])
            {
                q.push(curr->left);
                visited[curr->left] = true;
            }
            if(curr->right && !visited[curr->right])
            {
                q.push(curr->right);
                visited[curr->right] = true;
            }
            if(parent_track[curr] && !visited[parent_track[curr]] )
            {
                q.push(parent_track[curr]);
                visited[parent_track[curr]] = true;
            }
        }
    }
    vector<int> result;
    while(!q.empty())
    {
        Node* curr = q.front();
        q.pop();
        result.push_back(curr->val);
    }
    return result;
}
void printArray(vector<int>& arr)
{
    for(int num:arr)
    cout << num << " ";

    cout<<endl;
}

int main()
{
    Node* root = new Node(1);

   Node* target =  root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    root->right->left->left = new Node(12);
    root->right->left->right = new Node(13);
    root->right->right->left = new Node(14);
    root->right->right->right = new Node(15);

    vector<int> ans = NodesAtDistanceK(root,target,2);
    printArray(ans);
    return 0;
}
