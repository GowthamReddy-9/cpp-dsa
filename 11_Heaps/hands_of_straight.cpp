#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool isNStraightHand(vector<int>& hand, int groupSize){
        int n=hand.size();
        if(n%groupSize!=0) return false;
        priority_queue<int,vector<int>,greater<int>> pq;
        unordered_map<int,int> count;
        for(int i:hand) count[i]++;
        for(auto i:count) pq.push(i.first);
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            int cnt=count[top];
            if(cnt==0) continue;
            for(int i=1; i<groupSize; i++){
                if(count.find(top+i)!=count.end()){
                    if(count[top+i]<cnt) return false;
                    else count[top+i]-=cnt;
                }else return false;
            }
        }
        return true;
    }
};
int main()
{
    int n;
    cin>>n;
    int groupSize;
    cin>>groupSize;
    vector<int> hand;
    for(int i=0; i<n; i++){
        int card;
        cin>>card;
        hand.push_back(card);
    }
    Solution sol;
    sol.isNStraightHand(hand,groupSize)?cout<<"True":cout<<"False";
}