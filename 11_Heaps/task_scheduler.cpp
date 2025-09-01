#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(char c:tasks) freq[c-'A']++;
        priority_queue<int> pq;
        for(int i:freq) if(i) pq.push(i);
        int time=0;
        while(!pq.empty()){
            vector<int> remains;
            int cycle=n+1;
            while(cycle&&!pq.empty()){
                int top=pq.top(); pq.pop();
                if(top>1) remains.push_back(top-1);
                time++;
                cycle--;
            }
            for(int r: remains) pq.push(r);
            if(pq.empty()) break;
            time+=cycle;
        }
        return time;
    }
};
int main(){
    Solution s;
    vector<char> tasks={'A','A','C','B','B','D'};
    int n=2;
    cout<<s.leastInterval(tasks,n);
    return 0;
}