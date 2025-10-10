//GFG:Ceil in BST
//https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1

/**
 * Approach: Iterative Search
 * Track smallest value ≥ X while traversing BST.
 * Go left if node->data > X else right.
 * Time: O(h), Space: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int v) : data(v), left(NULL), right(NULL) {}
};

class Solution {
public:
    int findCeil(Node* root, int x) {
        int ceilVal = -1;
        while (root) {
            if (root->data == x) return root->data;
            else if (root->data > x) {
                ceilVal = root->data;
                root = root->left;
            } else root = root->right;
        }
        return ceilVal;
    }
};

int main() {
    /* BST:
            8
           / \
          4  12
         / \   \
        2  6   14
    */
    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->right = new Node(14);

    Solution s;
    vector<int> q = {1, 5, 10, 13, 15};
    for (int x : q)
        cout << "Ceil(" << x << ") = " << s.findCeil(root, x) << endl;

}
