/*
Problem: Root-to-Leaf Paths in a Binary Tree
Link:https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1
Approach: 
- Use DFS with a temporary path vector. 
- Push the current node, and if it's a leaf, save the path. 
- Otherwise, recurse into children. 
- Always backtrack by popping the node after recursion to restore the path.
*/

#include <bits/stdc++.h>
using namespace std;

/* Definition for Binary Tree Node */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    void dfs(Node* node, vector<vector<int>>& res, vector<int>& temp) {
        temp.push_back(node->data);

        // If it's a leaf node, store the path
        if (!node->left && !node->right) {
            res.push_back(temp);
        } else {
            if (node->left) dfs(node->left, res, temp);
            if (node->right) dfs(node->right, res, temp);
        }

        temp.pop_back(); // backtrack always
    }

    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> res;
        vector<int> temp;
        if (root) dfs(root, res, temp);
        return res;
    }
};

// Helper to print all paths
void printPaths(vector<vector<int>>& paths) {
    for (auto& path : paths) {
        for (int val : path) cout << val << " ";
        cout << "\n";
    }
}

int main() {
    /*
            1
           / \
          2   3
         / \
        4   5
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    vector<vector<int>> paths = sol.Paths(root);

    cout << "Root-to-Leaf Paths:\n";
    printPaths(paths);

    return 0;
}
