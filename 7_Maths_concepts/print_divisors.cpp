#include<bits/stdc++.h>
using namespace std;
vector<int> factors(int n){
	vector<int> low,high;
	for(int i=1; i*i<=n; i++){
		if(n%i==0){
			low.push_back(i);
			if(n/i!=i) high.push_back(n/i);
		}
	}
	reverse(high.begin(),high.end());
	low.insert(low.end(),high.begin(),high.end()); //doesn't required if we just counting factors.
	return low;
}
int main(){
	int n;
	cout<<"Input: ";
	cin>>n;
	cout<<endl;
	vector<int> answer=factors(n);
	for(auto it : answer){
		cout<<it<<" ";
	}
}
