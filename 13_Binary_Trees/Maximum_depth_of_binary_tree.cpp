//Leetcode 104:Maximum Depth Of a Binary Tree.
//https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// ------------------ DFS Recursive Version ------------------
int maxDepthDFS(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + max(maxDepthDFS(root->left), maxDepthDFS(root->right));
}

// ------------------ BFS Level Order Version ------------------
int maxDepthBFS(TreeNode* root) {
    if (root == nullptr) return 0;
    int height = 0;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        height++;
        int n = q.size();
        for (int i = 0; i < n; i++) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return height;
}

// ------------------ MAIN WITH TEST CASE ------------------
int main() {
    /*
            1
           / \
          2   3
         / \
        4   5
    Expected height: 3
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Height (DFS): " << maxDepthDFS(root) << endl;
    cout << "Height (BFS): " << maxDepthBFS(root) << endl;

    return 0;
}
