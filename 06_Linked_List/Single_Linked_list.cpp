#include<iostream>
#include<vector>
using namespace std;
class Node{
	public:
	int data;
	Node* next;
	
	Node(int d,Node* n){
		data=d;
		next=n;
	}
	Node(int d){
		data=d;
		next=NULL;
	}
};
Node* arrToLL(vector<int> nums){
	Node* head=new Node(nums[0]);
	Node* mover=head;
	for(int i=1; i<nums.size(); i++){
		Node* temp=new Node(nums[i]);
		mover->next=temp;
		mover=temp;
	}
	return head;
}
void PrintLL(Node* head){
	if(head==NULL) cout<<"Empty Linked list";
	Node* temp=head;
	while(temp){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
int LengthofLL(Node* head){
	int cnt=0;
	Node* temp=head;
	while(temp){
		cnt++;
		temp=temp->next;
	}
	return cnt;
}
void search(int val,Node* head){
	Node* temp=head;
	int count=0;
	while(temp){
		count++;
		if(temp->data==val){
		cout<<"Given Element Is Present At Pos: "<<count<<endl;
		return;
		}
		temp=temp->next;
	}
	cout<<"Given Element Is Not Present"<<endl;	
}
void deleteAtBegin(Node*& head){
	if(head==NULL) return;
	Node* temp= head;
	head=head->next;
	delete temp;
	
}
void deleteAtEnd(Node*& head){
	if(head==NULL) return;
	if(head->next==NULL){
	delete head;
	head=NULL;
	return;
	}
	Node* temp= head;
	while(temp->next->next){
	temp=temp->next;
	}
	delete temp->next;
	temp->next=NULL;
}
void deleteAtPos(Node*& head,int pos){
	if(head==NULL||pos==0) return;
	if(pos==1){
		Node* temp=head;
		head=head->next;
		delete temp;
		return;
	}
	Node* temp=head;
	Node* prev=NULL;
	int c=0;
	while(temp){
		c++;
		if(c==pos){
			prev->next=temp->next;
			delete temp;
			return;
		}
		prev=temp;
		temp=temp->next;
	}
	cout<<"--Position out of Bounds--"<<endl;
	
}
void insertAtBegin(Node*& head,int val){
	Node* newnode=new Node(val);
	if(head==NULL){
		head=newnode;
		return;
	}
	newnode->next=head;
	head=newnode;
	return;
}
void insertAtEnd(Node*& head,int val){
	Node* newnode=new Node(val);
	if(head==NULL){
		head=newnode;
		return;
	}
	Node* temp=head;
	while(temp->next){
		temp=temp->next;
	}
	temp->next=newnode;
	return;
}
void insertAtPos(Node*& head, int val, int pos){
	Node* newnode=new Node(val);
	if(head==NULL){
		if(pos==1){
		head=newnode;
		}else{
			cout<<"-- can't possible to insert at given pos --"<<endl;
		}
		return;
	}
	if(pos==1){
		newnode->next=head;
		head=newnode;
		return;
	}
	Node* temp=head;
	int c=0;
	while(temp){
		c++;
		if(c==pos-1){
			newnode->next=temp->next;
			temp->next=newnode;
			return;
		}
		temp=temp->next;
	}
	cout<<"-- can't possible to insert at given pos --"<<endl;
	
}
int main(){
	vector<int> nums={1,2,3,4,5,6,7,8};
	Node* head=arrToLL(nums);
	PrintLL(head);
	cout<<endl<<"Length: "<<LengthofLL(head)<<endl;
	search(12,head);
	search(2,head);
	deleteAtBegin(head);
	cout<<"--- Linked List after deletion at begin ---"<<endl;
	PrintLL(head);
	cout<<endl;
	insertAtBegin(head,1);
	cout<<"--- Linked List after insertion at begin ---"<<endl;
	PrintLL(head);
	cout<<endl;
	deleteAtEnd(head);
	cout<<"--- Linked List after deletion at end ---"<<endl;
	PrintLL(head);
	cout<<endl;
	insertAtEnd(head,8);
	cout<<"--- Linked List after insertion at end ---"<<endl;
	PrintLL(head);
	cout<<endl;
	deleteAtPos(head,4);
	cout<<"--- Linked List after deletion at pos 4 ---"<<endl;
	PrintLL(head);
	cout<<endl;
	insertAtPos(head,4,4);
	cout<<"--- Linked List after insertion at pos 4 ---"<<endl;
	PrintLL(head);
	cout<<endl;
	deleteAtPos(head,19);
}


