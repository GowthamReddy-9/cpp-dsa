//Iterative inorder traversal
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
    void iterativeInorder(Node* root){
        stack<Node*> st;
        Node* node=root;
        while(true){
            if(node!=NULL){
                st.push(node);
                node=node->left;
            }else{
                if(st.empty()) break;
                node=st.top(); st.pop();
                cout<<node->val<<" ";
                node=node->right;
            }
        }
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
    object.iterativeInorder(root);
    return 0;
}