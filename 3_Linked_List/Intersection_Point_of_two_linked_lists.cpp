// Problem: https://leetcode.com/problems/intersection-of-two-linked-lists/

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

void intersectAt(Node* headA, Node* headB, int pos) {
    if (pos == -1) return;
    Node* tempA = headA;
    for (int i = 0; i < pos && tempA; i++) tempA = tempA->next;
    Node* tempB = headB;
    while (tempB->next) tempB = tempB->next;
    tempB->next = tempA;
}

int getLength(Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

Node* getIntersectionNode(Node* headA, Node* headB) {
    int lenA = getLength(headA), lenB = getLength(headB);
    Node* longHead = lenA > lenB ? headA : headB;
    Node* shortHead = lenA > lenB ? headB : headA;
    int diff = abs(lenA - lenB);
    while (diff--) longHead = longHead->next;
    while (longHead && shortHead) {
        if (longHead == shortHead) return longHead;
        longHead = longHead->next;
        shortHead = shortHead->next;
    }
    return nullptr;
}

int main() {
    vector<int> listA = {1, 2, 3, 4, 5};
    vector<int> listB = {10, 20};
    Node* headA = buildList(listA);
    Node* headB = buildList(listB);
    intersectAt(headA, headB, 2); // Join at node with value 3 in listA

    Node* intersection = getIntersectionNode(headA, headB);
    if (intersection) {
        cout << "Intersection at node with value: " << intersection->data << endl;
    } else {
        cout << "No intersection found." << endl;
    }
    return 0;
}

