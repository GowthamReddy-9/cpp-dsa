//Leetcode 987: Vertical Order Traversal of a Binary Tree
//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/
#include <bits/stdc++.h>
using namespace std;

/*
Approach:
1. First used DFS + map, but it required sorting big vectors.
2. To avoid heavy sorting, switched to BFS so row order comes naturally.
3. Inside each level, sort (col, val) pairs, then push to map.
*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;

        map<int, vector<int>> mp; // column → values
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});

        while (!q.empty()) {
            int n = q.size();
            vector<pair<int,int>> temp; // store (col, val) for this level

            for (int i = 0; i < n; i++) {
                auto [col, node] = q.front();
                q.pop();

                if (node->left) q.push({col-1, node->left});
                if (node->right) q.push({col+1, node->right});
                temp.push_back({col, node->val});
            }

            sort(temp.begin(), temp.end()); // sort by col, then val
            for (auto& [c, v] : temp) {
                mp[c].push_back(v);
            }
        }

        for (auto& [col, vals] : mp) {
            res.push_back(vals);
        }
        return res;
    }
};


int main() {
    Solution sol;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> ans = sol.verticalTraversal(root);

    cout << "Vertical Traversal Output:\n";
    for (auto& col : ans) {
        cout << "[ ";
        for (int v : col) cout << v << " ";
        cout << "]\n";
    }
    return 0;
}

