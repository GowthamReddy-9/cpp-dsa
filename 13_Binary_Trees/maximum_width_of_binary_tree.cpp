//LeetCode 662. Maximum Width of Binary Tree
//https://leetcode.com/problems/maximum-width-of-binary-tree/description/

/**
 * Approach:
 * - Use BFS (level-order traversal) with a queue.
 * - Assign an index to each node as if it were in a complete binary tree:
 *      root = 0
 *      left child = 2*i
 *      right child = 2*i + 1
 * - For each level, width = last_index - first_index + 1.
 * - Normalize indices at each level (subtract the first index) to avoid overflow.
 * - Return the maximum width found.
 *
 * Complexity:
 * - Time: O(N), visit each node once.
 * - Space: O(W), max nodes at a level in queue.
 */

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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        long long max_width = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int n = q.size();
            long long left = q.front().second;
            long long right = q.back().second;
            max_width = max(max_width, right - left + 1);

            for (int i = 0; i < n; i++) {
                auto [node, idx] = q.front();
                q.pop();

                long long normalized = idx - left;  // normalize
                if (node->left) q.push({node->left, 2 * normalized});
                if (node->right) q.push({node->right, 2 * normalized + 1});
            }
        }
        return (int)max_width;
    }
};

// ---------- Test Case ----------
int main() {
    /*
         1
        / \
       3   2
      /     \
     5       9
    /         \
   6           7

   Widths:
   Level 0: [1] -> width = 1
   Level 1: [3, 2] -> width = 2
   Level 2: [5, null, null, 9] -> width = 4
   Level 3: [6,null,null,null,null,null,null,7] -> width = 8
   => Maximum width = 8
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->right->right = new TreeNode(9);
    root->left->left->left = new TreeNode(6);
    root->right->right->right = new TreeNode(7);

    Solution sol;
    cout << "Maximum width of binary tree: " << sol.widthOfBinaryTree(root) << endl;

    return 0;
}
