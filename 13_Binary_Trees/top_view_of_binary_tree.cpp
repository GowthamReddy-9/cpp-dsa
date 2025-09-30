//GFG:Top View of Binary Tree
//https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
#include <bits/stdc++.h>
using namespace std;

/*
Note:
I approached the problem first using an ordered map (map<int,int>) to keep track 
of the first node seen at each horizontal distance. That solution worked but had 
O(n log n) complexity due to map operations. 

Then I optimized it: instead of a map, I used an unordered_map<int,int> for O(1) 
lookups and tracked the min and max column indices during BFS. After traversal, 
I directly built the result vector from mincol to maxcol. This gave me an O(n) 
solution in both time and space.
*/

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        vector<int> ans;
        queue<pair<int,Node*>> q;
        if(root) q.push({0,root});
        unordered_map<int,int> mp;
        int mincol=INT_MAX;
        int maxcol=INT_MIN;

        while(!q.empty()){
            auto [col,node] = q.front();
            q.pop();
            mincol=min(mincol,col);
            maxcol=max(maxcol,col);

            if(mp.find(col)==mp.end()) 
                mp[col]=node->data;

            if(node->left) q.push({col-1,node->left});
            if(node->right) q.push({col+1,node->right});
        }

        for(int i=mincol; i<=maxcol; i++){
            ans.push_back(mp[i]);
        }
        return ans;
    }
};

// Simple test case
int main() {
    /*
            1
           / \
          2   3
           \   
            4
             \
              5
               \
                6
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);

    Solution sol;
    vector<int> res = sol.topView(root);

    cout << "Top View: ";
    for(int val : res) cout << val << " ";
    cout << endl;

    return 0;
}
