// LeetCode 19: Remove N-th Node From End of List
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

#include <iostream>
#include <vector>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Utility to convert vector to Linked List
ListNode* arrToLL(const vector<int>& nums) {
    if (nums.empty()) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* temp = head;
    for (int i = 1; i < nums.size(); i++) {
        temp->next = new ListNode(nums[i]);
        temp = temp->next;
    }
    return head;
}

// Utility to print linked list
void printLL(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Core logic
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == nullptr) return head;
    if (head->next == nullptr && n == 1) {
        delete head;
        return nullptr;
    }

    ListNode* fast = head;
    ListNode* slow = head;

    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }

    if (fast == nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }

    ListNode* del = slow->next;
    slow->next = slow->next->next;
    delete del;

    return head;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int n = 2;
    ListNode* head = arrToLL(nums);

    cout << "Before deletion: ";
    printLL(head);

    head = removeNthFromEnd(head, n);

    cout << "After deletion:  ";
    printLL(head);

    return 0;
}

