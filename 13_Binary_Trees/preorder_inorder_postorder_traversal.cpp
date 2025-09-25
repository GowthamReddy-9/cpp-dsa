#include<bits/stdc++.h>
using namespace std;
//Defination For a Binary Tree
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
    void preorderTraversal(Node* node){
        if(node==NULL) return;
        cout<<node->val<<" ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
    void inorderTraversal(Node* node){
        if(node==NULL) return;
        inorderTraversal(node->left);
        cout<<node->val<<" ";
        inorderTraversal(node->right);
    }
    void postorderTraversal(Node* node){
        if(node==NULL) return;
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout<<node->val<<" ";
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
    cout<<"Pre-Order: ";
    obj.preorderTraversal(root);
    cout<<endl;
    cout<<"In-Order: ";
    obj.inorderTraversal(root);
    cout<<endl;
    cout<<"Post-Order: ";
    obj.postorderTraversal(root);
    cout<<endl;
    return 0;
}