//Leetcode 114. Flatten Binary Tree to Linked List
//https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

/**
 * Approach: Morris-like Preorder Flatten
 * Flatten the binary tree to a linked list in-place (N → L → R order)
 * using Morris threading idea.
 * 1️. For each node, if left exists:
 *     - Find predecessor (rightmost in left subtree)
 *     - Connect predecessor->right to curr->right
 *     - Move curr->right = curr->left, curr->left = NULL
 * 2️. Move curr = curr->right
 * Time: O(n), Space: O(1)
 */

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
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr) {
            if (curr->left) {
                TreeNode* node = curr->left;
                while (node->right) node = node->right;
                node->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};

int main() {
    // Example tree:
    //      1
    //     / \
    //    2   5
    //   / \   \
    //  3   4   6

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    Solution s;
    s.flatten(root);

    // After flatten → 1 -> 2 -> 3 -> 4 -> 5 -> 6
    TreeNode* curr = root;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->right;
    }
    //  Expected Output: 1 2 3 4 5 6
    return 0;
}
