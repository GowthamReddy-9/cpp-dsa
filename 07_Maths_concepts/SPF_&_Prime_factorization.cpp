#include<bits/stdc++.h>
using namespace std;
//to return SPF(smallest prime factor)
//derived from Sieve of Eratosthenes
vector<int> SPF(int n){
	vector<int> ans(n+1);
	for(int i=1; i<=n; i++) ans[i]=i;
	for(int i=2; i<=n; i++){
		if(ans[i]==i){
			for(int j=i*i; j<=n; j+=i){
				if(ans[j]==j) ans[j]=i;
			}
		}
	}
	return ans;
}
void prime_factorization(vector<int>& query){
	for(int i=0; i<query.size(); i++){
		int n=query[i];
		vector<int> spf=SPF(n);
		cout<<"Prime Factorization of "<<n<<": ";
		while(n!=1){
			cout<<spf[n]<<" ";
			n=n/spf[n];
		}
		cout<<endl;
	}
}
int main(){
	vector<int> query={250,16,25,17,100};
	prime_factorization(query);
}
