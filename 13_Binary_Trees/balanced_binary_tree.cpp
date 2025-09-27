#include <bits/stdc++.h>
using namespace std;
//Leetcode 110:Balanced Binary Tree
//https://leetcode.com/problems/balanced-binary-tree/https://leetcode.com/problems/balanced-binary-tree/
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Recursive Version 
class RecursiveSolution {
public:
    int dfs(TreeNode* node) {
        if (!node) return 0;

        int left = dfs(node->left);
        if (left == -1) return -1; 

        int right = dfs(node->right);
        if (right == -1) return -1; 

        if (abs(left - right) > 1) return -1; 

        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
};

//Iterative Version
class IterativeSolution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;

        
        stack<tuple<TreeNode*, bool, int>> st;
        st.push({root, false, 0});

        unordered_map<TreeNode*, int> height; 

        while (!st.empty()) {
            auto [node, visited, h] = st.top();
            st.pop();

            if (!node) continue;

            if (!visited) {
            
                st.push({node, true, 0});
                
                st.push({node->right, false, 0});
                st.push({node->left, false, 0});
            } else {
                int left  = node->left  ? height[node->left]  : 0;
                int right = node->right ? height[node->right] : 0;

                if (abs(left - right) > 1) return false;

                height[node] = 1 + max(left, right);
            }
        }

        return true;
    }
};


int main() {
    /*
        Construct this test tree:
                 1
               /   \
              2     3
             / \
            4   5
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    RecursiveSolution rec;
    IterativeSolution iter;

    cout << "Recursive: " << (rec.isBalanced(root) ? "Balanced" : "Not Balanced") << endl;
    cout << "Iterative: " << (iter.isBalanced(root) ? "Balanced" : "Not Balanced") << endl;

    /*
        Now make tree unbalanced:
        Add extra nodes to left
    */
    root->left->left->left = new TreeNode(6);
    root->left->left->left->left = new TreeNode(7);

    cout << "Recursive: " << (rec.isBalanced(root) ? "Balanced" : "Not Balanced") << endl;
    cout << "Iterative: " << (iter.isBalanced(root) ? "Balanced" : "Not Balanced") << endl;

    return 0;
}
