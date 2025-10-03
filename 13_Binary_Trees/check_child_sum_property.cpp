#include <bits/stdc++.h>
using namespace std;
//https://www.geeksforgeeks.org/problems/children-sum-parent/1?utm_source=chatgpt.com
//GFG: Check Child Sum Property

/*
   Node structure for Binary Tree
*/
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

/*
   My approach :
   - For each node, I check if its left + right child sum == its data.
   - I do this recursively for the whole tree.
   - Base cases:
       -> empty node or leaf node is always valid.
   - If any node breaks the rule, I return 0 (false).
   - Otherwise, return 1 (true).
   - Overall complexity O(n), since I visit each node once.
*/

class Solution {
public:
    int isSumProperty(Node* root) {
        // if tree is empty or it's a leaf -> property holds
        if (!root) return 1;
        if (!root->left && !root->right) return 1;

        // check recursively on left and right subtree
        if (!isSumProperty(root->left) || !isSumProperty(root->right)) 
            return 0;

        // now check current node sum condition
        int leftVal = 0, rightVal = 0;
        if (root->left) leftVal = root->left->data;
        if (root->right) rightVal = root->right->data;

        // property holds only if root->data == sum of children
        return (root->data == leftVal + rightVal);
    }
};


int main() {
    /*
        Example tree:

              10
             /  \
            8    2
           / \    \
          3   5    2

        - 10 = 8 + 2
        - 8 = 3 + 5
        - 2 = 0 + 2
        - 3,5,2 are leaves => valid
        => Tree satisfies children sum property
    */

    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->right = new Node(2);

    Solution sol;
    cout << (sol.isSumProperty(root) ? "YES" : "NO") << endl;

    return 0;
}
