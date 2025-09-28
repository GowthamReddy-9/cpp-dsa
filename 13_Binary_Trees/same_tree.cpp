//LeetCode 100:Same Tree
//https://leetcode.com/problems/same-tree/description/
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    // Recursive DFS version
    bool isSameTreeRecursive(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;
        return isSameTreeRecursive(p->left, q->left) && isSameTreeRecursive(p->right, q->right);
    }

    // Iterative BFS version
    bool isSameTreeBFS(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*, TreeNode*>> qu;
        qu.push({p, q});

        while (!qu.empty()) {
            auto [n1, n2] = qu.front();
            qu.pop();

            if (!n1 && !n2) continue;
            if (!n1 || !n2) return false;
            if (n1->val != n2->val) return false;

            qu.push({n1->left, n2->left});
            qu.push({n1->right, n2->right});
        }
        return true;
    }
};

// ---------- Test ----------
int main() {
    /*
         Tree 1              Tree 2
            1                   1
           / \                 / \
          2   3               2   3
    */
    TreeNode* t1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* t2 = new TreeNode(1, new TreeNode(2), new TreeNode(3));

    Solution sol;
    cout << "Recursive Result: " << (sol.isSameTreeRecursive(t1, t2) ? "Same" : "Not Same") << endl;
    cout << "BFS Iterative Result: " << (sol.isSameTreeBFS(t1, t2) ? "Same" : "Not Same") << endl;

    return 0;
}
