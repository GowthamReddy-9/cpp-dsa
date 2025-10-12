//Leetcode 450. Delete Node in a BST
//https://leetcode.com/problems/delete-node-in-a-bst/description/

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        TreeNode* parent = nullptr;
        TreeNode* curr = root;

        //  Search for the node to delete
        while (curr && curr->val != key) {
            parent = curr;
            curr = (curr->val < key) ? curr->right : curr->left;
        }

        //  Node not found
        if (!curr) return root;

        //  Case 1 & 2: Node with 0 or 1 child
        if (!curr->left || !curr->right) {
            TreeNode* child = curr->left ? curr->left : curr->right;

            // connect parent to child (or update root if deleting root)
            if (!parent) root = child;
            else if (parent->left == curr) parent->left = child;
            else parent->right = child;

            delete curr;
        }
        //  Case 3: Node with 2 children
        else {
            // find rightmost node in left subtree
            TreeNode* node = curr->left;
            while (node->right) node = node->right;

            // attach right subtree to that node
            node->right = curr->right;

            // link parent (or update root)
            if (!parent) root = curr->left;
            else if (parent->left == curr) parent->left = curr->left;
            else parent->right = curr->left;

            delete curr;
        }

        return root;
    }
};

// Helper to print inorder
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    // Construct BST: 5,3,6,2,4,7
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    Solution s;
    cout << "Original Inorder: ";
    inorder(root);
    cout << endl;

    root = s.deleteNode(root, 3);  // delete node 3

    cout << "After Deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
