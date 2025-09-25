#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
    Node(int x) : val(x), prev(nullptr), next(nullptr), child(nullptr) {}
};

class Solution {
public:
    void helper(Node* temp,Node* next) {
        while(temp){ 
            if (temp->child) {
                Node* savednext = temp->next;
                temp->next = temp->child;
                temp->next->prev = temp;
                temp->child = nullptr;
                helper(temp->next,savednext);
            }
             if(temp->next==nullptr){
                    if(next){
                        temp->next=next;
                        next->prev=temp;
                        next=nullptr;
                    }else{
                        return;
                    }
                }
            temp=temp->next;
        }
    }
    Node* flatten(Node* head) {
        Node* temp = head;
        helper(temp,nullptr);
        return head;
    }
};

void print(Node* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Manually build a test case:
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);
    Node* n9 = new Node(9);
    Node* n10 = new Node(10);

    // Main list: 1 -> 2 -> 3
    n1->next = n2; n2->prev = n1;
    n2->next = n3; n3->prev = n2;

    // 3's child: 7 -> 8
    n3->child = n7;
    n7->next = n8; n8->prev = n7;

    // 8's child: 9 -> 10
    n8->child = n9;
    n9->next = n10; n10->prev = n9;

    Solution sol;
    Node* flat = sol.flatten(n1);
    print(flat); // Expected: 1 2 3 7 8 9 10

    return 0;
}

