//GFG:Merge two BST 's
//https://www.geeksforgeeks.org/problems/merge-two-bst-s/1

#include <bits/stdc++.h>
using namespace std;

/*
Approach:
---------
Brute → Better → Optimal
- Brute: Store inorder of both BSTs, then merge (O(n+m) space).
- Optimal: Use two stacks to simulate simultaneous inorder traversal (like two BST iterators).
  → Push all left nodes initially.
  → Repeatedly compare stack tops, take smaller node, and push its right subtree's left chain.
  → Drain any remaining nodes at end.

Time:  O(n + m)
Space: O(h1 + h2)
*/

class Node {
  public:
    int data;
    Node *left, *right;
    Node(int val) { data = val; left = right = nullptr; }
};

void push_left(Node* node, stack<Node*>& st) {
    while (node) {
        st.push(node);
        node = node->left;
    }
}

void drain_stack(stack<Node*>& st, vector<int>& ans) {
    while (!st.empty()) {
        Node* node = st.top(); st.pop();
        ans.push_back(node->data);
        push_left(node->right, st);
    }
}

class Solution {
  public:
    vector<int> merge(Node *root1, Node *root2) {
        stack<Node*> st1, st2;
        vector<int> ans;

        push_left(root1, st1);
        push_left(root2, st2);

        while (!st1.empty() && !st2.empty()) {
            Node* n1 = st1.top();
            Node* n2 = st2.top();

            if (n1->data < n2->data) {
                st1.pop();
                ans.push_back(n1->data);
                push_left(n1->right, st1);
            } else {
                st2.pop();
                ans.push_back(n2->data);
                push_left(n2->right, st2);
            }
        }

        drain_stack(st1, ans);
        drain_stack(st2, ans);
        return ans;
    }
};

// ----------------------------
// Example Test in main()
// ----------------------------
int main() {
    /*
            BST 1                 BST 2
              3                     4
             / \                   / \
            1   5                 2   6
    Expected merged inorder: [1, 2, 3, 4, 5, 6]
    */

    Node* root1 = new Node(3);
    root1->left = new Node(1);
    root1->right = new Node(5);

    Node* root2 = new Node(4);
    root2->left = new Node(2);
    root2->right = new Node(6);

    Solution s;
    vector<int> res = s.merge(root1, root2);

    cout << "Merged BST elements: ";
    for (int x : res) cout << x << " ";
    cout << endl;

    return 0;
}
