//LeetCode 106. Construct Binary Tree from Inorder and Postorder Traversal
//https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

/*
Approach:
- Use postorder (left → right → root) to pick roots backward.
- Use a hashmap for O(1) lookup of each root's index in inorder.
- Build the tree recursively: right first, then left.
- O(n) time, O(n) space (optimal).
*/
#include<bits/stdc++.h>
using namespace std;
//Tree Defination.
    struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    };
class Solution {
public:
    TreeNode* build(vector<int>& postorder, unordered_map<int,int>& idx,
                    int& postIndex, int l, int r) {
        if (l > r) return nullptr;

        int val = postorder[postIndex--];
        TreeNode* node = new TreeNode(val);
        int mid = idx[val];

        // Build right subtree first, then left (since we're moving backward)
        node->right = build(postorder, idx, postIndex, mid + 1, r);
        node->left  = build(postorder, idx, postIndex, l, mid - 1);

        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> idx;
        int n = postorder.size();
        for (int i = 0; i < n; i++) idx[inorder[i]] = i;

        int postIndex = n - 1;
        return build(postorder, idx, postIndex, 0, n - 1);
    }
    void Postorder(TreeNode* root){
        if(!root) return;
        Postorder(root->left);
        Postorder(root->right);
        cout << root->val << " ";
    };
};
int main() {
    vector<int> inorder   = {4, 2, 5, 6, 1, 3, 8, 9, 7, 10};
    vector<int> postorder = {4, 5, 6, 2, 8, 9, 10, 7, 3, 1};

    Solution sol;
    TreeNode* root = sol.buildTree(inorder, postorder);

    // verify using  postorder print
    cout << "Postorder of constructed tree: ";
    sol.Postorder(root);
    return 0;
}
