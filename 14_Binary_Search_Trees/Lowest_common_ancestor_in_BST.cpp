//Leetcode 235. Lowest Common Ancestor of a Binary Search Tree
//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

#include <bits/stdc++.h>
using namespace std;

/*
Approach:
Use BST property — 
if both p and q are smaller, go left;
if both are larger, go right;
else current node is LCA.
O(h) time, O(1) space.
*/

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if (p->val < root->val && q->val < root->val)
                root = root->left;      // both in left subtree
            else if (p->val > root->val && q->val > root->val)
                root = root->right;     // both in right subtree
            else
                return root;            // split point → LCA
        }
        return nullptr;
    }
};

int main() {
    /*
        Example BST:
                 6
               /   \
              2     8
             / \   / \
            0   4 7   9
               / \
              3   5

        p = 2, q = 8 → LCA = 6
        p = 2, q = 4 → LCA = 2
    */

    // Build BST
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    Solution sol;

    TreeNode* p = root->left;        // 2
    TreeNode* q = root->right;       // 8
    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);
    cout << "LCA of " << p->val << " and " << q->val << " = " << lca->val << endl;

    p = root->left;                  // 2
    q = root->left->right;           // 4
    lca = sol.lowestCommonAncestor(root, p, q);
    cout << "LCA of " << p->val << " and " << q->val << " = " << lca->val << endl;

    return 0;
}
