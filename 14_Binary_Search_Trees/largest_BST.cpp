//GFG : Largest BST
//https://www.geeksforgeeks.org/problems/largest-bst/1?utm_source=chatgpt.com
#include <bits/stdc++.h>
using namespace std;

/*
Approach:
----------
We need to find the size of the largest subtree that is a valid BST.
We use a postorder traversal (bottom-up):
1. For each node, gather info from left and right subtrees:
      - min value
      - max value
      - size of largest BST in that subtree
      - whether that subtree itself is BST
2. A node's subtree is BST if:
      left.isBST && right.isBST &&
      left.max < node->data < right.min
3. If BST → size = left.size + right.size + 1
   else   → size = max(left.size, right.size)
We return this info up to the root and the max size gives the answer.
Time Complexity: O(N)
Space Complexity: O(H)   [H = height of tree]
*/

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

struct NodeValue {
    int minNode;
    int maxNode;
    int maxSize;
    bool isBST;
    NodeValue(int mn, int mx, int sz, bool bst)
        : minNode(mn), maxNode(mx), maxSize(sz), isBST(bst) {}
};

class Solution {
public:
    NodeValue helper(Node* root) {
        if (!root)
            // empty subtree is a BST of size 0
            return NodeValue(INT_MAX, INT_MIN, 0, true);

        auto left = helper(root->left);
        auto right = helper(root->right);

        // If left and right subtrees are BSTs and the current node value
        // satisfies BST property
        if (left.isBST && right.isBST &&
            left.maxNode < root->data && root->data < right.minNode) {
            int newSize = left.maxSize + right.maxSize + 1;
            int newMin = min(root->data, left.minNode);
            int newMax = max(root->data, right.maxNode);
            return NodeValue(newMin, newMax, newSize, true);
        }

        // Otherwise, this subtree isn't a BST
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize), false);
    }

    int largestBst(Node* root) {
        return helper(root).maxSize;
    }
};

int main() {
    /*
        Example Tree (GFG sample)
                1
               / \
              4   4
             / \
            6   8

        Expected largest BST size = 1
    */

    Node* root = new Node(1);
    root->left = new Node(4);
    root->right = new Node(4);
    root->left->left = new Node(6);
    root->left->right = new Node(8);

    Solution sol;
    cout << "Largest BST size: " << sol.largestBst(root) << "\n";

    /*
        Output:
        Largest BST size: 1
    */

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
