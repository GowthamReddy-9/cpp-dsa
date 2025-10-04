//Leetcode 222. Count Complete Tree Nodes
//https://leetcode.com/problems/count-complete-tree-nodes/description/
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    // Utility: compute height by going leftmost
    int leftHeight(Node* node) {
        int h = 0;
        while (node) {
            h++;
            node = node->left;
        }
        return h;
    }

    // Utility: compute height by going rightmost
    int rightHeight(Node* node) {
        int h = 0;
        while (node) {
            h++;
            node = node->right;
        }
        return h;
    }

public:
    int countNodes(Node* root) {
        if (!root) return 0;

        int lh = leftHeight(root);
        int rh = rightHeight(root);

        // Case 1: Perfect tree
        if (lh == rh) {
            return (1 << lh) - 1; // 2^h - 1
        }

        // Case 2: Not perfect -> recurse
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

int main() {
    /*
        Example Tree:
                1
              /   \
             2     3
            / \   /
           4   5 6

        This is a complete binary tree.
        Expected count = 6
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    Solution sol;
    cout << "Total nodes = " << sol.countNodes(root) << "\n";

    return 0;
}
