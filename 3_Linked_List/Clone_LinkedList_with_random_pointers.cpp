#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        Node* temp = head;
        while (temp) {
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = copy->next;
        }

        temp = head;
        while (temp) {
            if (temp->random)
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }

        Node* dummy = new Node(-1);
        Node* curr = dummy;
        temp = head;
        while (temp) {
            curr->next = temp->next;
            temp->next = temp->next->next;
            curr = curr->next;
            temp = temp->next;
        }
        return dummy->next;
    }
};

// ?? Minimal main for testing (only `next` printed)
void print(Node* head) {
    while (head) {
        cout << "[" << head->val << ",";
        if (head->random) cout << head->random->val;
        else cout << "null";
        cout << "] ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;
    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);

    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;

    Node* result = sol.copyRandomList(head);
    print(result);  // Only prints values + randoms
    return 0;
}

