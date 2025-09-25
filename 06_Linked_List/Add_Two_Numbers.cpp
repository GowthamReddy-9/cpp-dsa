// LeetCode Link: https://leetcode.com/problems/add-two-numbers/

#include<iostream>
#include<vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        while (l1 || l2 || carry) {
            int sum = carry;

            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }

        return dummy->next;
    }
};

//  Helper: Convert vector<int> to Linked List
ListNode* vecToList(const vector<int>& nums) {
    if (nums.empty()) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* temp = head;
    for (int i = 1; i < nums.size(); ++i) {
        temp->next = new ListNode(nums[i]);
        temp = temp->next;
    }
    return head;
}

// Helper: Print Linked List
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Main function for testing
int main() {
    vector<int> num1 = {2, 4, 3}; // represents 342
    vector<int> num2 = {5, 6, 4}; // represents 465

    ListNode* l1 = vecToList(num1);
    ListNode* l2 = vecToList(num2);

    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);

    cout << "Sum: ";
    printList(result);  // Output: 7 -> 0 -> 8 (represents 807)
    return 0;
}

