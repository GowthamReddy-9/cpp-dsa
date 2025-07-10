#include<iostream>
#include<vector>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
		Node* prev;
		Node(int data1,Node* next1,Node* prev1){
			data=data1;
			next=next1;
			prev=prev1;
		}
		Node(int data1){
			data=data1;
			next=nullptr;
			prev=nullptr;
		}
};
void arrToDLL(vector<int> nums,Node*& head){
	head=new Node(nums[0]);
	Node* temp=head;
	for(int i=1; i<nums.size(); i++){
	    temp->next=new Node(nums[i],nullptr,temp);
	    temp=temp->next;
	}
	return;
}
void PrintFromEnd(Node* head){
	if(head==nullptr) return;
	Node* temp=head;
	while(temp->next) temp=temp->next;
	while(temp){
		cout<<temp->data<<" ";
		temp=temp->prev;
	}
	cout<<endl;
	return;
}
void PrintFromStart(Node* head){
	if(head==nullptr) return;
	Node* temp=head;
	while(temp){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
	return;
}
void insertAtHead(Node*& head,int val){
	if(head==nullptr){
		head=new Node(val);
		return;
	}
	head->prev=new Node(val,head,nullptr);
	head=head->prev;
	return;
}
void insertAtTail(Node*& head,int val){
	Node* newnode=new Node(val);
	if(head==nullptr){
		head=newnode;
		return;
	}
	Node* temp=head;
	while(temp->next) temp=temp->next;
	temp->next=newnode;
	newnode->prev=temp;
	return;
}
void insertAtPos(Node*& head,int val,int pos){
	Node* newnode= new Node(val);
	if(head==nullptr){
		if(pos==1){
			head=newnode;
			return;
		}
		cout<<"Invalid Position"<<endl;
		return;
	}
	if(pos==1){
		newnode->next=head;
		head->prev=newnode;
		head=newnode;
		return;
	}
	int c=0;
	Node* temp=head;
	while(temp){
		c++;
		if(c==pos-1){
			newnode->next = temp->next;
			newnode->prev = temp;
		if (temp->next != nullptr) {
    		temp->next->prev = newnode;
			}
			temp->next = newnode;
			return;
		}
		temp=temp->next;
	}
	cout<<"Invalid position"<<endl;
}
void DeleteHead(Node*& head){
	if(head==nullptr) return;
	Node* temp=head;
	head=head->next;
	if(head!=nullptr) head->prev=nullptr;
	delete temp;
}
void DeleteTail(Node*& head){
	if(head==nullptr) return;
	if(head->next==nullptr){
		delete head;
		head=nullptr;
		return;
	}
	Node* temp=head;
	while(temp->next){
		temp=temp->next;
	}
	temp->prev->next=nullptr;
	delete temp;
	return;
}
void DeleteAtPos(Node*& head,int pos){
	if(head==nullptr){
		cout<<"Empty List"<<endl;
		return;
	}
	Node* temp=head;
	int c=0;
	while(temp){
		c++;
		if(c==pos){
			if(temp->next==nullptr&&temp->prev==nullptr){
				delete temp;
				head=nullptr;
				return;
			}
			if(temp->next==nullptr){
				temp->prev->next=nullptr;
				delete temp;
				return;
			}
			if(temp->prev==nullptr){
				temp->next->prev=nullptr;
				head=temp->next;
				delete temp;
				return;
			}
			if(temp->next!=nullptr&&temp->prev!=nullptr){
				temp->prev->next=temp->next;
				temp->next->prev=temp->prev;
				delete temp;
				return;
			}
		}
		temp=temp->next;
	}
	cout<<"Ivalid Position"<<endl;
}
int main(){
	vector<int> nums={1,2,3,4,5,6,7,8};
	Node* head;
	arrToDLL(nums,head);
	PrintFromStart(head);
	PrintFromEnd(head);
	insertAtHead(head,9);
	PrintFromStart(head);
	DeleteHead(head);
	PrintFromStart(head);
	insertAtTail(head,9);
	PrintFromStart(head);
	DeleteTail(head);
	PrintFromStart(head);
	insertAtPos(head,9,5);
	PrintFromStart(head);
	DeleteAtPos(head,5);
	PrintFromStart(head);
}
