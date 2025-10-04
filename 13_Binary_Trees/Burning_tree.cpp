//GFG : Burning Tree
//https://www.geeksforgeeks.org/problems/burning-tree/1

#include <bits/stdc++.h>
using namespace std;

// Node Defination
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution {
    /*
    
    Approach 1: BFS + Parent Map
    - First I do BFS from root and build a parent map for each node.
    - At the same time, I also find the target node.
    - Then I start another BFS from the target node.
    - At each step I "burn" its left child, right child and parent (if not already burned).
    - Use an unordered_set (visited/unburned) to ensure each node is burned only once.
    - Count the levels of BFS → that’s the time taken.
    Complexity: O(n) time, O(n) space.
    */
    int bfsBurn(Node* root, int target) {
        unordered_map<Node*, Node*> parent;
        unordered_set<Node*> unburned;
        queue<Node*> q;
        Node* target_node = NULL;

        if (root) q.push(root);
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            if (node->data == target) target_node = node;
            unburned.insert(node);
            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        int time = 0;
        if (target_node) {
            q.push(target_node);
            unburned.erase(target_node); // mark target burned
        }

        while (!q.empty()) {
            int n = q.size();
            bool burned = false;
            for (int i = 0; i < n; i++) {
                Node* node = q.front();
                q.pop();
                if (node->left && unburned.erase(node->left)) {
                    q.push(node->left);
                    burned = true;
                }
                if (node->right && unburned.erase(node->right)) {
                    q.push(node->right);
                    burned = true;
                }
                if (parent[node] && unburned.erase(parent[node])) {
                    q.push(parent[node]);
                    burned = true;
                }
            }
            if (burned) time++;
        }
        return time;
    }

    /*
    Approach 2: DFS (Recursive)
    - I do DFS to find the target node.
    - When I reach the target, I burn its subtree downward (helper function).
    - While recursion unwinds, I calculate time for fire to go upward to parent
      and then down into the opposite subtree.
    - I keep track of maximum time seen across all paths.
    - This avoids parent map and queue → single DFS pass.
    Complexity: O(n) time, O(h) stack space.
    */

    void spreadFire(Node* node, int time, int &maxTime) {
        if (!node) return;
        maxTime = max(maxTime, time);
        spreadFire(node->left, time + 1, maxTime);
        spreadFire(node->right, time + 1, maxTime);
    }

    int dfsBurn(Node* node, int target, int &maxTime) {
        if (!node) return -1;

        if (node->data == target) {
            spreadFire(node, 0, maxTime);
            return 0;
        }

        int left = dfsBurn(node->left, target, maxTime);
        if (left != -1) {
            maxTime = max(maxTime, left + 1); // burning parent
            spreadFire(node->right, left + 2, maxTime); // burn opposite subtree
            return left + 1;
        }

        int right = dfsBurn(node->right, target, maxTime);
        if (right != -1) {
            maxTime = max(maxTime, right + 1);
            spreadFire(node->left, right + 2, maxTime);
            return right + 1;
        }

        return -1;
    }

  public:
    int minTime_BFS(Node* root, int target) {
        return bfsBurn(root, target);
    }

    int minTime_DFS(Node* root, int target) {
        int maxTime = 0;
        dfsBurn(root, target, maxTime);
        return maxTime;
    }
};

// ----------------------
// Testcase
// ----------------------
int main() {
    /*
            1
           / \
          2   3
         / \
        4   5
           /
          6
    Target = 5
    Expected burn time = 3
    Path:
    Time 0: 5
    Time 1: 2,6
    Time 2: 1,4
    Time 3: 3
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);

    Solution sol;
    cout << "BFS version: " << sol.minTime_BFS(root, 5) << "\n";
    cout << "DFS version: " << sol.minTime_DFS(root, 5) << "\n";

    return 0;
}
