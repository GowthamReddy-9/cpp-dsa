//GFG:Inorder Successor in BST
//https://www.geeksforgeeks.org/problems/inorder-successor-in-bst/1

#include <bits/stdc++.h>
using namespace std;

/*
Approach:
Iterative O(h) time, O(1) space.
1. Search for node x while tracking last node where we took a left turn (possible successor).
2. If x has right subtree → successor is leftmost node in right subtree.
3. Else → successor is the tracked parent.
*/

// Definition for BST Node
struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
    // Returns the inorder successor of node x in BST rooted at 'root'
    int inOrderSuccessor(Node *root, Node *x) {
        Node* parent = nullptr;
        int ans = -1;

        // Step 1: Find node x while tracking potential parent
        while (root) {
            if (root->data == x->data) break;
            else if (root->data > x->data) {
                parent = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }

        // Step 2: Case 1 - right subtree exists
        if (root && root->right) {
            root = root->right;
            while (root->left) root = root->left;
            ans = root->data;
        }
        // Step 3: Case 2 - no right subtree
        else if (parent) {
            ans = parent->data;
        }

        return ans;
    }
};

// Helper function to insert nodes into BST
Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

int main() {
    /*
            20
           /  \
         10    30
         / \
        5  15
           \
            17
    */

    Node* root = nullptr;
    vector<int> vals = {20, 10, 30, 5, 15, 17};
    for (int v : vals) root = insert(root, v);

    Node* x = root->left->right; // Node with value 15
    Solution sol;
    cout << "Inorder Successor of " << x->data << " is: "
         << sol.inOrderSuccessor(root, x) << endl;

    return 0;
}
