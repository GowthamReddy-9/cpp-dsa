//Leetcode 701. Insert into a Binary Search Tree
//https://leetcode.com/problems/insert-into-a-binary-search-tree/description/

/**
 * Approach: Iterative BST Insertion
 * Traverse from root, find correct null spot for val,
 * and insert new node maintaining BST property.
 * Time: O(h), Space: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        TreeNode* curr = root;
        while (curr) {
            if (curr->val < val) {
                if (curr->right) curr = curr->right;
                else {
                    curr->right = new TreeNode(val);
                    break;
                }
            } else {
                if (curr->left) curr = curr->left;
                else {
                    curr->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    /* BST:
            8
           / \
          4  12
         / \   \
        2  6   14
    */
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(4);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(6);
    root->right->right = new TreeNode(14);

    Solution s;
    root = s.insertIntoBST(root, 10);

    cout << "Inorder after insertion: ";
    inorder(root);
    // Expected: 2 4 6 8 10 12 14
}
