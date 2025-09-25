#include<bits/stdc++.h>
using namespace std;
//1<=l<r;
vector<int> get_Sieve(int n){
	vector<int> sieve(n+1,1);
	for(int i=2; i*i<=n; i++){
		if(sieve[i]==1){
			for(int j=i*i; j<=n; j+=i){   
				sieve[j]=0;
			}
		}
	}
	return sieve;
}
void prime_count(vector<vector<int>>& query){
	for(int i=0; i<query.size(); i++){
		int l=query[i][0];
		int r=query[i][1];
		vector<int> primes=get_Sieve(r);
		for(int i=2; i<primes.size(); i++){
			primes[i]+=primes[i-1];
		}
		cout<<primes[r]-primes[l-1]<<" ";
	}
}
int main(){
	vector<vector<int>> query;
	vector<int> a={2,13};
	vector<int> b={1,1000};
	vector<int> c={5,19};
	query.push_back(a);
	query.push_back(b);
	query.push_back(c);
	prime_count(query);
}
