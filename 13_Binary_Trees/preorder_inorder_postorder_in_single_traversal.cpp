#include<bits/stdc++.h>
using namespace std;
//Defination For a Binary Tree
//All Three DFS in Single Traversal.
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
    void Traverse(Node* root,vector<int>& Preorder,vector<int>& Inorder,vector<int>& Postorder){
        if(root==NULL) return;
        stack<pair<Node*,int>> st;
        st.push({root,1});
        while(!st.empty()){
            auto top=st.top(); st.pop();
            if(top.second==1){
                Preorder.push_back(top.first->val);
                top.second++;
                st.push(top);
                if(top.first->left) st.push({top.first->left,1});
            }else if(top.second==2){
                Inorder.push_back(top.first->val);
                top.second++;
                st.push(top);
                if(top.first->right) st.push({top.first->right,1});
            }else{
                Postorder.push_back(top.first->val);
            }
        }
        return;
    }
};
int main(){

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
    Solution obj;
    vector<int> preorder;
    vector<int> inorder;
    vector<int> postorder;
    obj.Traverse(root,preorder,inorder,postorder);
    cout<<"Preorder: ";
    for(auto i:preorder) cout<<i<<" ";
    cout<<endl;
    cout<<"Inorder: ";
    for(auto i:inorder) cout<<i<<" ";
    cout<<endl;
    cout<<"Postorder: ";
    for(auto i:postorder) cout<<i<<" ";
    cout<<endl;
}