//GFG:Floor In BST
//https://www.geeksforgeeks.org/problems/floor-in-bst/1
/**
 * Approach: Iterative Search
 * Track largest value ≤ X while traversing BST.
 * Go right if node->data < X else left.
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
    int findFloor(Node* root, int x) {
        int floorVal = -1;
        while (root) {
            if (root->data == x) return root->data;
            else if (root->data < x) {
                floorVal = root->data;
                root = root->right;
            } else root = root->left;
        }
        return floorVal;
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
        cout << "Floor(" << x << ") = " << s.findFloor(root, x) << endl;

}
