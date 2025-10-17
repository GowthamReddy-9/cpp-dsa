//LeetCode 653. Two Sum IV - Input is a BST
//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    // Push all left nodes (for next smallest)
    void push_left(TreeNode* node, stack<TreeNode*>& st) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

    // Push all right nodes (for next largest)
    void push_right(TreeNode* node, stack<TreeNode*>& st) {
        while (node) {
            st.push(node);
            node = node->right;
        }
    }

public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        // Two stacks to simulate two BST iterators
        stack<TreeNode*> left, right;
        push_left(root, left);   // inorder traversal (smallest first)
        push_right(root, right); // reverse inorder traversal (largest first)

        // Two-pointer logic directly on BST
        while (!left.empty() && !right.empty() && left.top() != right.top()) {
            int sum = left.top()->val + right.top()->val;

            if (sum == k) return true;
            else if (sum < k) {
                // Move left iterator forward
                TreeNode* node = left.top();
                left.pop();
                push_left(node->right, left);
            } else {
                // Move right iterator backward
                TreeNode* node = right.top();
                right.pop();
                push_right(node->left, right);
            }
        }

        return false;
    }
};

// ---------------- MAIN FUNCTION FOR TESTING ----------------
int main() {
    /*
        Example BST:
              5
             / \
            3   6
           / \   \
          2   4   7
    */

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3, new TreeNode(2), new TreeNode(4));
    root->right = new TreeNode(6, nullptr, new TreeNode(7));

    Solution sol;

    int k1 = 9; // 2 + 7 = 9 -> true
    int k2 = 28; // no such pair -> false

    cout << boolalpha;
    cout << "Target " << k1 << ": " << sol.findTarget(root, k1) << endl;
    cout << "Target " << k2 << ": " << sol.findTarget(root, k2) << endl;

    return 0;
}
