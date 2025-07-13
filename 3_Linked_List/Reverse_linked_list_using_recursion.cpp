// LeetCode: https://leetcode.com/problems/reverse-linked-list/

#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Recursive reverse function
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};

// Convert vector to linked list
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

// Print linked list
void printLL(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function
int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    ListNode* head = arrToLL(nums);

    cout << "Original List: ";
    printLL(head);

    Solution sol;
    head = sol.reverseList(head);

    cout << "Reversed List: ";
    printLL(head);

    return 0;
}

