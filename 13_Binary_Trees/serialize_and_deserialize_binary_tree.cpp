
//Leetcode 297:https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
#include <bits/stdc++.h>
using namespace std;

/* Node structure */
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    /* BFS serialize: use 'n' for nulls, ',' for split */
    string serialize(TreeNode* root) {
        if (!root) return "n,";
        string data;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (!node) { data += "n,"; continue; }
            data += to_string(node->val) + ",";
            q.push(node->left);
            q.push(node->right);
        }
        return data;
    }

    /* BFS deserialize: rebuild using same order */
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string token;
        getline(ss, token, ',');
        if (token == "n") return nullptr;

        TreeNode* root = new TreeNode(stoi(token));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (!getline(ss, token, ',')) break;
            if (token != "n") {
                node->left = new TreeNode(stoi(token));
                q.push(node->left);
            }
            if (!getline(ss, token, ',')) break;
            if (token != "n") {
                node->right = new TreeNode(stoi(token));
                q.push(node->right);
            }
        }
        return root;
    }
};

/* Test the codec */
int main() {
    // Build:     1
    //           / \
    //          2   3
    //             / \
    //            4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec ser, deser;
    string s = ser.serialize(root);
    cout << "Serialized: " << s << "\n";

    TreeNode* ans = deser.deserialize(s);
    cout << "Root after deserialization: " << ans->val << "\n";  // 1
}
