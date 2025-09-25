#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

//  Convert vector to linked list
Node* arrToLL(const vector<int>& nums) {
    if (nums.empty()) return nullptr;
    Node* head = new Node(nums[0]);
    Node* temp = head;
    for (int i = 1; i < nums.size(); i++) {
        temp->next = new Node(nums[i]);
        temp = temp->next;
    }
    return head;
}

//  Print linked list
void printLL(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Your implementation goes here
Node* sortList012(Node*& head) {
	if(head==nullptr || head->next==nullptr) return head;
    Node* temp=head;
    Node* head0=new Node(-1);
    Node* head1=new Node(-1);
    Node* head2=new Node(-1);
    Node* l0=head0;
    Node* l1=head1;
    Node* l2=head2;
    while(temp){
    	if(temp->data==0){
    		l0->next=temp;
    		l0=temp;
		}else if(temp->data==1){
    		l1->next=temp;
    		l1=temp;
		}else if(temp->data==2){
    		l2->next=temp;
    		l2=temp;
		}
    	temp=temp->next;
	}
	l0->next=(head1->next!=nullptr)?head1->next:head2->next;
	l1->next=head2->next;
	l2->next=nullptr;
	head=head0->next;
    return head;
}

int main() {
    vector<int> nums = {0,1,2,0,1,1,2,0,2};
    Node* head = arrToLL(nums);

    cout << "Before sorting: ";
    printLL(head);

    head = sortList012(head);  // You write this

    cout << "After sorting:  ";
    printLL(head);

    return 0;
}

