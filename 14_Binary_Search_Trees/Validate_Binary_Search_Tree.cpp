//Leetcode 98. Validate Binary Search Tree
//https://leetcode.com/problems/validate-binary-search-tree/description/

//  Approach: Recursively carry valid range (min, max) down the tree
// Each node's value must lie strictly between minVal and maxVal
// Time: O(N), Space: O(H)

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool helper(TreeNode* node, long long minVal, long long maxVal) {
        if (!node) return true;
        if (node->val <= minVal || node->val >= maxVal) return false;
        return helper(node->left, minVal, node->val) &&
               helper(node->right, node->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, LLONG_MIN, LLONG_MAX);
    }
};

// 🔹 Testcase
int main() {
    /*
            5
           / \
          3   7
             / \
            6   8
    */
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    Solution s;
    cout << (s.isValidBST(root) ? "Valid BST" : "Invalid BST") << endl;
}
