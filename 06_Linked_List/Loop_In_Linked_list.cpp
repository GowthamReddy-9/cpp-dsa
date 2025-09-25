#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

// Converts vector to linked list and returns head
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

// Creates loop in the list: connects last node to node at position (0-indexed)
void createLoop(Node* head, int pos) {
    if (pos == -1 || !head) return;
    Node* loopNode = nullptr;
    Node* curr = head;
    int index = 0;
    while (curr->next) {
        if (index == pos) loopNode = curr;
        curr = curr->next;
        index++;
    }
    curr->next = loopNode;
}

// Detect loop
bool detectLoop(Node* head) {
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

// Count nodes in loop
int countLoopLength(Node* head) {
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            int count = 1;
            Node* temp = slow->next;
            while (temp != slow) {
                count++;
                temp = temp->next;
            }
            return count;
        }
    }
    return 0;
}

// Detect start of loop
Node* getLoopStart(Node* head) {
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node* head = buildList(arr);
    createLoop(head, 2); // Connect last node to node at index 2 (value = 3)

    cout << "Loop Detected: " << (detectLoop(head) ? "Yes" : "No") << endl;
    cout << "Loop Length: " << countLoopLength(head) << endl;

    Node* loopStart = getLoopStart(head);
    if (loopStart) {
        cout << "Loop starts at node with value: " << loopStart->data << endl;
    } else {
        cout << "No loop start node (no loop)." << endl;
    }

    return 0;
}

