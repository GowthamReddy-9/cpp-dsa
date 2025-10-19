//Leetcode 1932. Merge BSTs to Create Single BST
//https://leetcode.com/problems/merge-bsts-to-create-single-bst/description/
//My LeetCode Solution :https://leetcode.com/problems/merge-bsts-to-create-single-bst/solutions/7285887/c-hashmap-recursion-clean-fully-commented-o-n-solution-merge-bst-s-to-create-single-bst

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
    // Recursively merges subtrees if a leaf matches another tree's root
    void mergeHelper(TreeNode* node, unordered_map<int, TreeNode*>& rootMap) {
        if (!node) return;
        // If left child exists in rootMap, attach that tree and erase it
        if (node->left && rootMap.find(node->left->val) != rootMap.end()) {
            node->left = rootMap[node->left->val];
            rootMap.erase(node->left->val);
        }
        // If right child exists in rootMap, attach that tree and erase it
        if (node->right && rootMap.find(node->right->val) != rootMap.end()) {
            node->right = rootMap[node->right->val];
            rootMap.erase(node->right->val);
        }
        // Continue merging recursively for both children
        mergeHelper(node->left, rootMap);
        mergeHelper(node->right, rootMap);
    }

    // Checks if the tree is a valid BST within the given value bounds
    bool isValidBst(TreeNode* node, long long mini, long long maxi) {
        if (!node) return true;
        if (node->val <= mini || node->val >= maxi) return false;
        return isValidBst(node->left, mini, node->val) &&
               isValidBst(node->right, node->val, maxi);
    }

public:
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int, TreeNode*> parent;  // Maps child value -> parent node
        unordered_map<int, TreeNode*> rootMap; // Stores all current roots

        // Build maps for all roots and their child relationships
        for (TreeNode* t : trees) {
            rootMap[t->val] = t;
            if (t->left) {
                parent[t->left->val] = t;
            }
            if (t->right) {
                parent[t->right->val] = t;
            }
        }

        TreeNode* root = NULL; // Will store the final root

        // Find the unique root (node that has no parent)
        for (TreeNode* t : trees) {
            if (!parent[t->val]) {
                if (!root) root = t;
                else return nullptr; // More than one possible root -> invalid
            }
        }

        if (!root) return nullptr; // No root found -> invalid case

        // Merge all possible subtrees starting from root
        mergeHelper(root, rootMap);

        // After merging, there should be only one tree left in map
        if (rootMap.size() != 1) return nullptr;

        // Validate final merged tree as a proper BST
        if (!isValidBst(root, LONG_MIN, LONG_MAX)) return nullptr;

        return root; // Return the merged BST
    }
};

// Utility function to print inorder traversal (for testing)
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    /*
      Example test case:
      trees = [[2,1,3],[1,null,null],[3,null,null]]
      Expected merged BST: [2,1,3]
    */

    TreeNode* t1 = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    TreeNode* t2 = new TreeNode(1);
    TreeNode* t3 = new TreeNode(3);
    vector<TreeNode*> trees = {t1, t2, t3};

    Solution sol;
    TreeNode* merged = sol.canMerge(trees);

    if (merged) {
        cout << "Merged BST (Inorder): ";
        inorder(merged);
        cout << endl;
    } else {
        cout << "Cannot merge into a valid BST." << endl;
    }

    return 0;
}
