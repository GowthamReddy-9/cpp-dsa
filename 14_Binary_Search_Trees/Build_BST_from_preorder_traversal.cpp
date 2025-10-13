//Leetcode 1008. Construct Binary Search Tree from Preorder Traversal
//https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/

#include <bits/stdc++.h>
using namespace std;

/*
Approach:
Use a stack to maintain ancestors.
For each value in preorder:
 - If it's smaller than stack.top(), it's the left child.
 - If it's greater, pop until you find correct parent → right child.
O(n) time, O(h) space.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty()) return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> st;
        st.push(root);

        for (int i = 1; i < preorder.size(); ++i) {
            TreeNode* node = new TreeNode(preorder[i]);
            TreeNode* parent = nullptr;

            // Pop until we find the node where this value fits as the right child
            while (!st.empty() && preorder[i] > st.top()->val) {
                parent = st.top();
                st.pop();
            }

            if (parent)
                parent->right = node;   // current value is right child of last popped node
            else
                st.top()->left = node;  // current value is left child of top node

            st.push(node);
        }
        return root;
    }
};

// Helper: Inorder traversal (should print sorted sequence for a BST)
void inorderTraversal(TreeNode* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    /*
        Example:
        Preorder: [8, 5, 1, 7, 10, 12]
        Constructed BST:
                  8
                /   \
               5     10
              / \      \
             1   7      12

        Inorder traversal → 1 5 7 8 10 12
    */

    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    Solution sol;
    TreeNode* root = sol.bstFromPreorder(preorder);

    cout << "Inorder Traversal of Constructed BST: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
