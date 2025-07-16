// LeetCode #2095: Delete the Middle Node of a Linked List
// Problem Link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Convert vector to linked list
Node* arrToLL(const vector<int>& nums) {
    if (nums.empty()) return nullptr;
    Node* head = new Node(nums[0]);
    Node* temp = head;
    for (int i = 1; i < nums.size(); i++) {
        temp->next = new Node(nums[i]);
        temp = temp->next;
    }
    return head;
}

// Print linked list
void printLL(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Delete middle node
Node* deleteMiddle(Node* head) {
    if (head == nullptr) return nullptr;
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* slow = head;
    Node* fast = head;
    Node* prev = nullptr;

    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = slow->next;
    delete slow;

    return head;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    Node* head = arrToLL(nums);

    cout << "Original Linked List: ";
    printLL(head);

    head = deleteMiddle(head);

    cout << "After Deleting Middle Node: ";
    printLL(head);

    return 0;
}

