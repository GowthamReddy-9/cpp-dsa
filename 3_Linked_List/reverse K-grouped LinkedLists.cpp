#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* returnKthnode(ListNode* head, int k) {
        int count = 0;
        while (head) {
            count++;
            if (count == k) return head;
            head = head->next;
        }
        return nullptr;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next) return head;

        ListNode* temp = head;
        ListNode* prev = nullptr;

        while (temp) {
            ListNode* kth = returnKthnode(temp, k);
            if (!kth) break;

            ListNode* nextnode = kth->next;
            kth->next = nullptr;

            ListNode* newhead = reverseList(temp);

            if (temp == head)
                head = newhead;
            else
                prev->next = newhead;

            temp->next = nextnode;
            prev = temp;
            temp = nextnode;
        }

        return head;
    }
};

//  Minimal main for testing
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;
    ListNode* result = sol.reverseKGroup(head, k);
    printList(result);  // Expected: 2 1 4 3 5
    return 0;
}

