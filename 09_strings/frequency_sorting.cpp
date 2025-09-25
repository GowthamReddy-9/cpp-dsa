#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for(auto it:s){
        	freq[it]++;
		}
		priority_queue<pair<int,char>> pq;
		for(auto it:freq){
			char c=it.first;
			int count=it.second;
			pq.push({count,c});
		}
		string result="";
		while(!pq.empty()){
			int count=pq.top().first;
			char c=pq.top().second;
			pq.pop();
			result+=string(count,c);
		}
		return result;
    }
};

int main() {
    Solution sol;
    string input = "tree";
    string output = sol.frequencySort(input);
    
    cout << "Sorted by frequency: " << output << endl;
    // Expected: "eetr" or "eert" (any valid frequency sorted variant)
    
    return 0;
}

