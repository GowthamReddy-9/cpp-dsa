//LeetCode 863. All Nodes Distance K in Binary Tree
//https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* 
   Approach 1: BFS with parent map
   - First store each node's parent using BFS
   - Then from target do BFS again, moving left, right, and parent
   - Keep track of distance, when distance == k collect all nodes
*/
class SolutionBFS {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (!root || !target) return {};
        if (k == 0) return { target->val };

        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        unordered_map<TreeNode*, bool> visited;
        q.push(target);
        visited[target] = true;
        int dist = 0;

        while (!q.empty()) {
            int sz = q.size();
            if (dist == k) {
                vector<int> res;
                while (!q.empty()) {
                    res.push_back(q.front()->val);
                    q.pop();
                }
                return res;
            }
            for (int i = 0; i < sz; ++i) {
                TreeNode* node = q.front(); q.pop();
                if (parent.count(node)) {
                    TreeNode* p = parent[node];
                    if (p && !visited[p]) {
                        visited[p] = true;
                        q.push(p);
                    }
                }
                if (node->left && !visited[node->left]) {
                    visited[node->left] = true;
                    q.push(node->left);
                }
                if (node->right && !visited[node->right]) {
                    visited[node->right] = true;
                    q.push(node->right);
                }
            }
            dist++;
        }
        return {};
    }
};

/*
   Approach 2: DFS recursion single traversal
   - If node == target, collect all nodes k distance below
   - While returning back, calculate distance from target
   - If current node is k distance, add it
   - If target found in one subtree, search opposite subtree
*/
class SolutionDFS {
public:
    vector<int> res;
    int K;

    void subtreeAdd(TreeNode* node, int dist) {
        if (!node) return;
        if (dist == K) {
            res.push_back(node->val);
            return;
        }
        subtreeAdd(node->left, dist + 1);
        subtreeAdd(node->right, dist + 1);
    }

    int dfs(TreeNode* node, TreeNode* target) {
        if (!node) return -1;
        if (node == target) {
            subtreeAdd(node, 0);
            return 0;
        }

        int leftDist = dfs(node->left, target);
        if (leftDist != -1) {
            if (leftDist + 1 == K) res.push_back(node->val);
            else subtreeAdd(node->right, leftDist + 2);
            return leftDist + 1;
        }

        int rightDist = dfs(node->right, target);
        if (rightDist != -1) {
            if (rightDist + 1 == K) res.push_back(node->val);
            else subtreeAdd(node->left, rightDist + 2);
            return rightDist + 1;
        }

        return -1;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        res.clear();
        K = k;
        dfs(root, target);
        return res;
    }
};

/* -------------------- TESTCASES --------------------------- */
int main() {
    // build sample tree:
    //         3
    //       /   \
    //      5     1
    //     / \   / \
    //    6   2 0   8
    //       / \
    //      7   4
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* target = root->left; // node 5

    SolutionBFS solBFS;
    SolutionDFS solDFS;

    cout << "BFS answer (target=5, k=2): ";
    vector<int> ans1 = solBFS.distanceK(root, target, 2);
    for (int x : ans1) cout << x << " ";
    cout << "\n";

    cout << "DFS answer (target=5, k=2): ";
    vector<int> ans2 = solDFS.distanceK(root, target, 2);
    for (int x : ans2) cout << x << " ";
    cout << "\n";

    // Edge test: k=0
    cout << "BFS answer (target=5, k=0): ";
    vector<int> ans3 = solBFS.distanceK(root, target, 0);
    for (int x : ans3) cout << x << " ";
    cout << "\n";

    cout << "DFS answer (target=5, k=0): ";
    vector<int> ans4 = solDFS.distanceK(root, target, 0);
    for (int x : ans4) cout << x << " ";
    cout << "\n";

    return 0;
}
