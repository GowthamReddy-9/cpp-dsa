#include<bits/stdc++.h>
using namespace std;
void Sieve_primes(int n,vector<int>& answer){
	vector<int> hashArr(n+1,1);
	for(int i=2; i*i<=n; i++){
		if(hashArr[i]==1){
			for(int j=i*i; j<=n; j+=i){   
				hashArr[j]=0;
			}
		}
	}
	for(int i=2; i<=n; i++){
		if(hashArr[i]==1) answer.push_back(i);
	}
}
int main()
{
	int n;
	cout<<"Input: ";
	cin>>n;
	vector<int> answer;
	Sieve_primes(n,answer);
	for(auto it : answer){
		cout<<it<<" ";
	}
}
