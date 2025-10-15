#include <bits/stdc++.h>
using namespace std;
//Leetcode 1382. Balance a Binary Search Tree
//https://leetcode.com/problems/balance-a-binary-search-tree/description/


/*
Approach:
1. Do inorder traversal to get sorted nodes (BST property).
2. Rebuild balanced BST using middle element as root recursively.
   → Left half → left subtree, right half → right subtree.
   Time: O(n), Space: O(n)
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    void dfs(TreeNode* node, vector<TreeNode*>& inorder) {
        if (!node) return;
        dfs(node->left, inorder);
        inorder.push_back(node);
        dfs(node->right, inorder);
    }

    TreeNode* buildBalanced(vector<TreeNode*>& inorder, int l, int r) {
        if (l > r) return nullptr;
        int mid = l + (r - l) / 2;
        TreeNode* node = inorder[mid];
        node->left = buildBalanced(inorder, l, mid - 1);
        node->right = buildBalanced(inorder, mid + 1, r);
        return node;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> inorder;
        dfs(root, inorder);
        return buildBalanced(inorder, 0, inorder.size() - 1);
    }
};

// Helper function to print inorder traversal
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// Example test case
int main() {
    /*
        Unbalanced BST:
              10
             /
            8
           /
          7
         /
        6
    */
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(8);
    root->left->left = new TreeNode(7);
    root->left->left->left = new TreeNode(6);

    Solution sol;
    TreeNode* balanced = sol.balanceBST(root);

    cout << "Inorder of Balanced BST: ";
    printInorder(balanced);
    cout << endl;

    return 0;
}
