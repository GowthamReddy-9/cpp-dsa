//Iterative postorder traversal
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
    void iterativePostorder2stack(Node* root){
        if(root==NULL) return;
        stack<Node*> st1;
        stack<Node*> st2;
        st1.push(root);
        while(!st1.empty()){
            Node* node=st1.top(); st1.pop();
            st2.push(node);
            if(node->left) st1.push(node->left);
            if(node->right) st1.push(node->right);
        }
        cout<<"Using 2 Stacks: ";
        while(!st2.empty()){
            Node* node=st2.top(); st2.pop();
            cout<<node->val<<" ";
        }
        cout<<endl;
        return;
    }
    void iterativePostorder1stack(Node* root){
        stack<Node*> st;
        Node* curr=root;
        cout<<"Using 1 stack: ";
        while(curr!=NULL||!st.empty()){
            if(curr!=NULL){
                st.push(curr);
                curr=curr->left;
            }else{
                Node* temp=st.top()->right;
                if(temp==NULL){
                    temp=st.top(); st.pop();
                    cout<<temp->val<<" ";
                    while(!st.empty()&&temp==st.top()->right){
                        temp=st.top(); st.pop();
                        cout<<temp->val<<" ";
                    }
                }else{
                    curr=temp;
                }
            }
        }
        return;
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
    object.iterativePostorder2stack(root);
     object.iterativePostorder1stack(root);
    return 0;
}