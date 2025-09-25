#include<bits/stdc++.h>
using namespace std;
//using basic method
int gcd_1(int n1,int n2){
	if(n1>n2) return gcd_1(n2,n1);  //we just need n1 as smaller number.
	int gcd=1;
	for(int i=2; i<=n1; i++){
		if(n1%i==0&&n2%i==0) gcd=i;
	}
	return gcd;
}
//using Euclidean Algorithm 
int gcd_2(int n1,int n2){
	//imagine a>b
	//the Euclidean Algorithm states that gcd(a,b)==gcd(a%b,b);
	//repeat untill a becomes 0 the b should be your answer;
	while(n1>0&&n2>0){
		if(n1>n2) n1=n1%n2;
		else n2=n2%n1;
	}
	if(n1==0) return n2;
	return n1;
}
int main(){
	//Note: if gcd(a,b)==1 they are co-prime.
	cout<<gcd_1(21,18)<<endl; 
	cout<<gcd_2(12,18)<<endl;
}
