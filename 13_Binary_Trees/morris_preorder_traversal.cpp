//Morris Preorder Traversal

/**
 *  Approach: Morris Preorder Traversal
 * Traverse preorder (N → L → R) without recursion or stack.
 * 1️. If no left child → visit & move right.
 * 2️. Else find inorder predecessor (rightmost in left subtree):
 *     - If predecessor’s right == NULL → visit, link to curr, move left.
 *     - Else → remove link, move right.
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        while (curr) {
            if (curr->left) {
                TreeNode* node = curr->left;
                while (node->right && node->right != curr) node = node->right;
                if (node->right) {
                    node->right = NULL;
                    curr = curr->right;
                } else {
                    ans.push_back(curr->val);
                    node->right = curr;
                    curr = curr->left;
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
    vector<int> res = s.preorderTraversal(root);

    for (int x : res) cout << x << " ";
    // Expected Output: 1 2 3
    return 0;
}
