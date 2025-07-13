// Problem: https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x) : data(x), next(nullptr), prev(nullptr) {}
};

Node* buildDLL(const vector<int>& arr) {
    if (arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* curr = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        curr->next = temp;
        temp->prev = curr;
        curr = temp;
    }
    return head;
}

void printDLL(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " <-> ";
        head = head->next;
    }
    cout << endl;
}

class Solution {
public:
    Node* deleteAllOccurOfX(Node* head, int x) {
        Node* temp = head;
        while (temp) {
            if (temp->data == x) {
                if (temp == head) {
                    head = temp->next;
                }
                Node* nextnode = temp->next;
                Node* prevnode = temp->prev;
                if (nextnode) nextnode->prev = prevnode;
                if (prevnode) prevnode->next = nextnode;
                delete temp;
                temp = nextnode;
            } else {
                temp = temp->next;
            }
        }
        return head;
    }
};

int main() {
    vector<int> values = {1, 2, 3, 2, 4, 2, 5};
    int x = 2;

    Node* head = buildDLL(values);
    cout << "Original DLL: ";
    printDLL(head);

    Solution sol;
    head = sol.deleteAllOccurOfX(head, x);

    cout << "After deleting " << x << ": ";
    printDLL(head);

    return 0;
}

