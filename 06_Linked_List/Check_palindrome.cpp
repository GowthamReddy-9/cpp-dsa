// LeetCode Problem: 234. Palindrome Linked List
// Link: https://leetcode.com/problems/palindrome-linked-list/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Reverse a singly linked list (iterative)
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    while (head) {
        ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

// Check if a linked list is a palindrome
bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;

    // Step 1: Find middle of the list
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse second half
    ListNode* second = reverseList(slow->next);
    ListNode* first = head;
    ListNode* restore = second;

    // Step 3: Compare both halves
    bool isPalin = true;
    while (second) {
        if (first->val != second->val) {
            isPalin = false;
            break;
        }
        first = first->next;
        second = second->next;
    }

    // Step 4: Restore the list (optional but clean)
    reverseList(restore);
    return isPalin;
}

// Driver for testing
int main() {
    // Example: 1 ? 2 ? 2 ? 1
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    if (isPalindrome(head)) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not a palindrome" << endl;
    }

    return 0;
}

