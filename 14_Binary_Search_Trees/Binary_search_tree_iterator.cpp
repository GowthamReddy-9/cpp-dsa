//LeetCode 173. Binary Search Tree Iterator
//https://leetcode.com/problems/binary-search-tree-iterator/description/

#include <bits/stdc++.h>
using namespace std;

/*
Approach:
---------
Use a stack to simulate inorder traversal lazily (Left → Node → Right).
- Push all left children initially.
- On each `next()`:
    - Pop top node (the next inorder element).
    - If it has a right child, push all its left descendants.
Time: O(1) amortized per call
Space: O(h), where h = tree height
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator {
public:
    stack<TreeNode*> st;
    
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }

    void pushLeft(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }
    
    int next() {
        TreeNode* top = st.top();
        st.pop();
        if (top->right) pushLeft(top->right);
        return top->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

// ----------------------------
// Example Test in main()
// ----------------------------
int main() {
    // Construct the BST
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);
    
    // Test the iterator
    BSTIterator it(root);
    cout << "Inorder Traversal using BSTIterator: ";
    while (it.hasNext()) {
        cout << it.next() << " ";
    }
    cout << endl;

    // Expected: 1 3 4 6 7 8 10 13 14
    return 0;
}
