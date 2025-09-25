//BFS or Level order search
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(){
        val=0;
        left=NULL;
        right=NULL;
    }
    Node(int data){
        val=data;
        left=NULL;
        right=NULL;
    }
    Node(int data,Node* leftnode,Node* rightnode){
        val=data;
        left=leftnode;
        right=rightnode;
    }
};
class Solution{
    public:
    vector<vector<int>> levelOrder(Node* root){
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int n=q.size();
            for(int i=0; i<n; i++){
                Node* node=q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
int main()
{
     /*
            1
           / \
          2   3
         / \   \
        4   5   6
       /   / \   \
      7   8   9   10
                 /
                11
    */
   Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->right = new Node(6);

    root->left->left->left = new Node(7);

    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);

    root->right->right->right = new Node(10);
    root->right->right->right->left = new Node(11); 
    Solution object;
    vector<vector<int>> levels;
    levels=object.levelOrder(root);
    int n=levels.size();
    for(int i=0; i<n; i++){
        for(int j:levels[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}