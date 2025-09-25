#include<bits/stdc++.h>
using namespace std;
string to_binary(int n){
	string res="";
	while(n!=0){
		if(n%2==1) res+="1";
		else res+="0";
		n=n/2;
	}
	int l=0;
	int r=res.size()-1;
	while(l<r){
		swap(res[l],res[r]);
		l++;
		r--;
	}
	return res;
}
int to_decimal(string x){
	int num=0;
	int power=1;
	int len=x.size();
	for(int i=len-1; i>=0; i--){
		if(x[i]=='1'){
			num+=power;
		}
		power*=2;
	}
	return num;
}
int main()
{
	int x=25;
	string binary=to_binary(x);
	cout<<binary<<endl;
	int decimal=to_decimal(binary);
	cout<<decimal;
}
