//Morris Inorder Traversal

/**
 * Approach: Morris Inorder Traversal
 * Traverse inorder (L → N → R) without recursion or stack.
 * 1️. If no left child → visit & move right.
 * 2. Else find inorder predecessor (rightmost node in left subtree):
 *     - If predecessor’s right == NULL → link it to current, move left.
 *     - Else → remove link, visit current, move right.
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        while (curr) {
            if (curr->left) {
                TreeNode* node = curr->left;
                while (node->right && node->right != curr)
                    node = node->right;
                if (!node->right) {
                    node->right = curr;
                    curr = curr->left;
                } else {
                    node->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            } else {
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        return ans;
    }
};

int main() {
    // Example tree:
    //      1
    //       \
    //        2
    //       /
    //      3

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution s;
    vector<int> res = s.inorderTraversal(root);

    for (int x : res) cout << x << " ";
    // Expected Output: 1 3 2
    return 0;
}
