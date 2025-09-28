//Leetcode 543:Diameter of Binary Tree
//https://leetcode.com/problems/diameter-of-binary-tree/description/
#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// ---------------- Recursive Version ----------------
class RecursiveSolution {
public:
    int dfs(TreeNode* node, int& diameter) {
        if (!node) return 0;
        int lh = dfs(node->left, diameter);
        int rh = dfs(node->right, diameter);
        diameter = max(diameter, lh + rh);
        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        dfs(root, diameter);
        return diameter;
    }
};
// ---------------- Iterative Version ----------------
class IterativeSolution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        int diameter = 0;
        stack<pair<TreeNode*, bool>> st;
        unordered_map<TreeNode*, int> height;

        st.push({root, false});
        while (!st.empty()) {
            auto [node, visited] = st.top();
            st.pop();
            if (!node) continue;

            if (visited) {
                int lh = node->left ? height[node->left] : 0;
                int rh = node->right ? height[node->right] : 0;
                diameter = max(diameter, lh + rh);
                height[node] = 1 + max(lh, rh);
            } else {
                st.push({node, true});
                st.push({node->right, false});
                st.push({node->left, false});
            }
        }
        return diameter;
    }
};

// ---------------- Test Case ----------------
int main() {
    /*
         1
        / \
       2   3
      / \
     4   5

    Diameter = 3 (path: 4 -> 2 -> 5 OR 4 -> 2 -> 1 -> 3)
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    RecursiveSolution rec;
    IterativeSolution itr;

    cout << "Recursive Diameter: " << rec.diameterOfBinaryTree(root) << endl;
    cout << "Iterative Diameter: " << itr.diameterOfBinaryTree(root) << endl;

    return 0;
}
