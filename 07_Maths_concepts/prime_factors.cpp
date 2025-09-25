#include<bits/stdc++.h>
using namespace std;
bool check_prime(int n){
	if(n <= 1) return false;
    for(int i = 2; i * i <= n; ++i){
        if(n % i == 0) return false;
    }
    return true; 
}
//brute method
void prime_factors1(int n,vector<int>& ans){
	for(int i=2; i<=n; i++){
		if(check_prime(i)&&n%i==0) ans.push_back(i);
	}
}
//sqrt method
void prime_factors2(int n,vector<int>& ans){
	for(int i=2; i*i<=n; i++){
		if(n%i==0){
			ans.push_back(i);
			while(n%i==0){
				n=n/i;
			}
		}
	}
	if(n!=1) ans.push_back(n);
}
int main()
{
	vector<int> ans1;
	vector<int> ans2;
	prime_factors1(98,ans1);
	for(auto it:ans1){
		cout<<it<<" ";
	}
	cout<<endl;
	prime_factors1(98,ans2);
	for(auto it:ans2){
		cout<<it<<" ";
	}
}
