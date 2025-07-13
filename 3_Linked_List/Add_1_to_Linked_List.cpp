// Problem: https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

Node* buildList(const vector<int>& arr) {
    if (arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* curr = head;
    for (int i = 1; i < arr.size(); ++i) {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }
    return head;
}

void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int addOneUtil(Node* node) {
    if (!node) return 1;
    int carry = addOneUtil(node->next);
    int sum = node->data + carry;
    node->data = sum % 10;
    return sum / 10;
}

Node* addOne(Node* head) {
    int carry = addOneUtil(head);
    if (carry) {
        Node* newHead = new Node(carry);
        newHead->next = head;
        return newHead;
    }
    return head;
}

int main() {
    vector<int> num = {9, 9, 9};
    Node* head = buildList(num);
    cout << "Original number: ";
    printList(head);
    head = addOne(head);
    cout << "After adding 1: ";
    printList(head);
    return 0;
}

