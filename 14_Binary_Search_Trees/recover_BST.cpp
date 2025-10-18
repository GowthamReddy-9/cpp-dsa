//Leetcode 99. Recover Binary Search Tree
//https://leetcode.com/problems/recover-binary-search-tree/description/
#include <bits/stdc++.h>
using namespace std;

// Approach: Morris Inorder Traversal (O(1) space)
// ------------------------------------------------
// Inorder traversal of BST should be sorted.
// If two nodes are swapped, there will be 1 or 2 inversions where prev->val > curr->val.
// Detect both nodes and swap at end.
// Morris traversal lets us traverse inorder without stack/recursion
// by temporarily creating "threads" (right pointers from predecessor).


//--Defination for tree--
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *second = nullptr;
        TreeNode *prev = nullptr, *curr = root;

        while (curr) {
            if (!curr->left) {
                // Process current node
                if (prev && prev->val > curr->val) {
                    if (!first) first = prev;
                    second = curr;
                }
                prev = curr;
                curr = curr->right;
            } else {
                // Find inorder predecessor
                TreeNode* pred = curr->left;
                while (pred->right && pred->right != curr)
                    pred = pred->right;

                if (!pred->right) {
                    // Make thread
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    // Remove thread and process node
                    pred->right = nullptr;
                    if (prev && prev->val > curr->val) {
                        if (!first) first = prev;
                        second = curr;
                    }
                    prev = curr;
                    curr = curr->right;
                }
            }
        }

        if (first && second) swap(first->val, second->val);
    }
};

// Example test
int main() {
    // Construct a tree: [3,1,4,null,null,2]
    // Swapped nodes: 3 and 2
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    Solution().recoverTree(root);

    // After fix -> inorder should be: 1 2 3 4
    TreeNode* curr = root;
    stack<TreeNode*> st;
    while (curr || !st.empty()) {
        while (curr) { st.push(curr); curr = curr->left; }
        curr = st.top(); st.pop();
        cout << curr->val << " ";
        curr = curr->right;
    }
    cout << endl;
}
