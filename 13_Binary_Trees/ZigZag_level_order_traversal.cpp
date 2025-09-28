//Leetcode 103:Binary Tree Zigzag Level Order Traversal
//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int n = q.size();
            vector<int> temp(n);
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front(); q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);

                int idx = leftToRight ? i : (n - 1 - i);
                temp[idx] = node->val;
            }
            ans.push_back(temp);
            leftToRight = !leftToRight;
        }
        return ans;
    }
};

int main() {
    // Build the test tree
    /*
    Example tree:

            1
           / \
          2   3
         / \   \
        4   5   6

    Zigzag Level Order Output:
    [[1], [3,2], [4,5,6]]
*/

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution sol;
    vector<vector<int>> result = sol.zigzagLevelOrder(root);

    for (auto &level : result) {
        for (int val : level) cout << val << " ";
        cout << endl;
    }
    return 0;
}
