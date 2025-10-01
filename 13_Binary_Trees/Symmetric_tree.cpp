//Leetcode 101. Symmetric Tree
//https://leetcode.com/problems/symmetric-tree/description/
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
/**
 *Use a queue to perform a BFS traversal, but instead of processing single nodes, always process them in pairs.
  Each pair should represent mirror positions in the tree.
  For each pair:
  If both are nullptr → continue.
  If only one is nullptr → tree is not symmetric.
  If values differ → tree is not symmetric.
  If valid, push their children into the queue in mirrored order:
  left->left with right->right
  left->right with right->left 
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;

        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);

        while (!q.empty()) {
            TreeNode* left = q.front(); q.pop();
            TreeNode* right = q.front(); q.pop();

            if (!left && !right) continue;
            if (!left || !right) return false;
            if (left->val != right->val) return false;

            // Push children in mirrored order
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        return true;
    }
};

// ---------- Test ----------
int main() {
    Solution sol;

    // Example 1: Symmetric tree
    //       1
    //     /   \
    //    2     2
    //   / \   / \
    //  3   4 4   3
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(4);
    root1->right->left = new TreeNode(4);
    root1->right->right = new TreeNode(3);

    cout << (sol.isSymmetric(root1) ? "Symmetric" : "Not Symmetric") << endl;

    // Example 2: Not symmetric
    //       1
    //     /   \
    //    2     2
    //     \     \
    //      3     3
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(2);
    root2->left->right = new TreeNode(3);
    root2->right->right = new TreeNode(3);

    cout << (sol.isSymmetric(root2) ? "Symmetric" : "Not Symmetric") << endl;

    return 0;
}
