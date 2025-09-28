//Leetcode 124:Binary Tree Maximum Path Sum
//https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    // ---------- Recursive Version ----------
    int dfs(TreeNode* node, int &maxSum) {
        if (!node) return 0;
        int left = max(0, dfs(node->left, maxSum));
        int right = max(0, dfs(node->right, maxSum));
        maxSum = max(maxSum, left + right + node->val);
        return max(left, right) + node->val;
    }

public:
    int maxPathSumRecursive(TreeNode* root) {
        int maxSum = INT_MIN;
        dfs(root, maxSum);
        return maxSum;
    }
    // ---------- Iterative Version ----------
    int maxPathSumIterative(TreeNode* root) {
        if (!root) return 0;

        int maxSum = INT_MIN;
        unordered_map<TreeNode*, int> contrib; // stores contribution of each node
        stack<pair<TreeNode*, bool>> st;

        st.push({root, false});
        while (!st.empty()) {
            auto [node, visited] = st.top();
            st.pop();
            if (!node) continue;

            if (visited) {
                int left = node->left ? max(0, contrib[node->left]) : 0;
                int right = node->right ? max(0, contrib[node->right]) : 0;
                maxSum = max(maxSum, left + right + node->val);
                contrib[node] = max(left, right) + node->val;
            } else {
                st.push({node, true});
                st.push({node->right, false});
                st.push({node->left, false});
            }
        }
        return maxSum;
    }
};

// ---------- Test ----------
int main() {
    /*
             -10
             /  \
            9   20
               /  \
              15   7
    */

    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20, new TreeNode(15), new TreeNode(7));

    Solution sol;
    cout << "Recursive Max Path Sum: " << sol.maxPathSumRecursive(root) << endl;
    cout << "Iterative Max Path Sum: " << sol.maxPathSumIterative(root) << endl;

    return 0;
}
