//GFG: Bottom view of Binary Tree
//https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
#include <bits/stdc++.h>
using namespace std;

/*
Note:
I approached the problem in the same way as the Top View. 
The only difference is that instead of storing the first 
node seen in a column, I simply overwrote the value in that 
column whenever a new node was found. This ensures that the 
last node encountered in each column is the one from the 
bottom view.
*/

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> res;
        unordered_map<int,int> mp;
        queue<pair<int,Node*>> q;
        int mincol=INT_MAX;
        int maxcol=INT_MIN;
        if(root) q.push({0,root});

        while(!q.empty()){
            auto [col,node] = q.front();
            q.pop();
            mincol = min(mincol,col);
            maxcol = max(maxcol,col);

            // overwrite the value for bottom view
            mp[col] = node->data;

            if(node->left) q.push({col-1,node->left});
            if(node->right) q.push({col+1,node->right});
        }

        for(int i=mincol; i<=maxcol; i++){
            res.push_back(mp[i]);
        }
        return res;
    }
};

// Simple test case
int main() {
    /*
            20
           /  \
          8   22
         / \     \
        5  3      25
          / \
         10 14

    Bottom view should be: 5 10 3 14 25
    */

    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->right = new Node(25);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    Solution sol;
    vector<int> res = sol.bottomView(root);

    cout << "Bottom View: ";
    for(int val : res) cout << val << " ";
    cout << endl;

    return 0;
}
