//GFG :https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
/*
Boundary Traversal of Binary Tree
Problem: Print the boundary nodes of a binary tree in anti-clockwise order:
1. Root node
2. Left boundary (excluding leaf nodes)
3. All leaf nodes (from left to right)
4. Right boundary (excluding leaf nodes, in reverse order)
Approach:
- Use three helper functions:
  - leftBoundary (iterative): traverse down the left edge until no left child (or right child fallback).
  - leafNodes (recursive): collect all leaves in L -> R DFS order.
  - rightBoundary (recursive): traverse down the right edge, then add nodes while recursion unwinds (to get reverse order).
  -  used isLeaf() to avoid leafNodes in left and right boundaries.
- Time complexity: O(N), each node visited once.
- Space complexity: O(H) due to recursion stack, where H = height of tree.
*/

#include <bits/stdc++.h>
using namespace std;

// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
    bool isLeaf(Node* node) {
        return !node->left && !node->right;
    }

    void leftBoundary(Node* node, vector<int>& ans) {
        while (node) {
            if (!isLeaf(node)) ans.push_back(node->data);
            if (node->left) node = node->left;
            else node = node->right;
        }
    }

    void leafNodes(Node* node, vector<int>& ans) {
        if (!node) return;
        if (isLeaf(node)) ans.push_back(node->data);
        leafNodes(node->left, ans);
        leafNodes(node->right, ans);
    }

    void rightBoundary(Node* node, vector<int>& ans) {
        if (!node) return;
        if (node->right) rightBoundary(node->right, ans);
        else rightBoundary(node->left, ans);
        if (!isLeaf(node)) ans.push_back(node->data);
    }

  public:
    vector<int> boundaryTraversal(Node* root) {
        vector<int> ans;
        if (!root) return ans;
        ans.push_back(root->data);
        if (isLeaf(root)) return ans;

        leftBoundary(root->left, ans);
        leafNodes(root, ans);
        rightBoundary(root->right, ans);

        return ans;
    }
};

// Test case
int main() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
           / \
          7   8
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(8);

    Solution sol;
    vector<int> ans = sol.boundaryTraversal(root);

    for (int x : ans) cout << x << " ";
    return 0;
}
