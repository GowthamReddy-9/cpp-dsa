//Leetcode105. Construct Binary Tree from Preorder and Inorder Traversal
//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

/*
Approach:
- Use preorder to pick the root sequentially.
- Use a hashmap for O(1) lookup of each root's index in inorder.
- Recursively build left & right subtrees using inorder index boundaries.
- O(n) time, O(n) space (optimal).
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int preIndex = 0;
    unordered_map<int,int> idx;

    TreeNode* build(vector<int>& preorder, int l, int r) {
        if (l > r) return nullptr;
        int val = preorder[preIndex++];
        TreeNode* node = new TreeNode(val);
        int mid = idx[val];
        node->left = build(preorder, l, mid - 1);
        node->right = build(preorder, mid + 1, r);
        return node;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) idx[inorder[i]] = i;
        return build(preorder, 0, inorder.size() - 1);
    }
};

// Test
int main() {
    vector<int> preorder = {1,2,4,6,5,3,7,8,9,10};
    vector<int> inorder  = {4,2,5,6,1,3,8,9,7,10};

    Solution sol;
    TreeNode* root = sol.buildTree(preorder, inorder);

    // Verification: print inorder
    function<void(TreeNode*)> printIn = [&](TreeNode* n){
        if(!n) return;
        printIn(n->left); cout << n->val << " "; printIn(n->right);
    };

    printIn(root);
}
