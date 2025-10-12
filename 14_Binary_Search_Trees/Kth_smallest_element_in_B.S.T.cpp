//Leetcode 230. Kth Smallest Element in a BST
//https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

/**
 *  Approach: Inorder Traversal (Recursive)
 * - Do an inorder traversal (Left → Root → Right).
 * - Decrement k at each node visited.
 * - When k becomes 0, current node is the kth smallest.
 * - Time: O(H + k),  Space: O(H)
 */

#include <bits/stdc++.h>
using namespace std;

// ---- Tree Node Definition ----
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// ---- Solution ----
class Solution {
    int inorder(TreeNode* node, int& k) {
        if(!node) return -1;

        int left = inorder(node->left, k);
        if(left != -1) return left;

        if(--k == 0) return node->val;

        return inorder(node->right, k);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        return inorder(root, k);
    }
};

// ---- Helper to build a sample BST ----
TreeNode* insert(TreeNode* root, int val) {
    if(!root) return new TreeNode(val);
    if(val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

// ---- Main (Testcase) ----
int main() {
    /*
           5
          / \
         3   6
        / \
       2   4
      /
     1
    */

    vector<int> vals = {5,3,6,2,4,1};
    TreeNode* root = nullptr;
    for(int v : vals) root = insert(root, v);

    Solution s;
    int k = 3;
    cout << "Kth Smallest (" << k << "): " << s.kthSmallest(root, k) << endl;

    return 0;
}
