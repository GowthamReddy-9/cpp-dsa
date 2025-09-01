#include<bits/stdc++.h>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) const {
            return a->val > b->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr)
                pq.push(lists[i]);
        }
        ListNode* head = new ListNode();
        ListNode* temp = head;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            temp->next = top;
            temp = temp->next;
            if (top->next != nullptr)
                pq.push(top->next);
        }
        ListNode* result = head->next;
        delete head;
        return result;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<ListNode*> lists;
    for(int i=0; i<n; i++){
        int k;
        cin>>k;
        ListNode* head=new ListNode();
        ListNode* temp=head;
        for(int i=0; i<k; i++){
            int val;
            cin>>val;
            ListNode* newnode=new ListNode(val);
            temp->next=newnode;
            temp=temp->next;
        }
        lists.push_back(head->next);
    }
    Solution solution;
    ListNode* temp=solution.mergeKLists(lists);
    while(temp!=nullptr){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}