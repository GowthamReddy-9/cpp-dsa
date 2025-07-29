#include<bits/stdc++.h>
using namespace std;
bool check_prime(int n){
	if(n <= 1) return false;
    for(int i = 2; i * i <= n; ++i){
        if(n % i == 0) return false;
    }
    return true; 
}
int main(){
	vector<int> nums = {7, 10, 2, 15, 11, 21};
	for(auto it : nums){
		if(check_prime(it)) cout<<it<<" is prime.";
		else cout<<it<<" is not prime.";
		cout<<endl;
	}
}
