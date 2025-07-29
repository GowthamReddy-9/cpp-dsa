#include<bits/stdc++.h>
using namespace std;
int cal_pow(int n, int p){
	if(n==1||n==0) return n; 
	int ans=1;
	if(p==0) return ans*1;
	if(p==1) return ans*n;
	if(p%2==1){
		ans=ans*n;
		p=p-1;
	}
	n=n*n;
	p=p/2;
	ans=ans*cal_pow(n,p);
	return ans;
}
int main()
{
	int n;
	int p;
	cout<<"Enter Digit: ";
	cin>>n;
	cout<<endl<<"Enter Power: ";
	cin>>p;
	cout<<endl;
	//actual inbuilt function
	cout<<pow(n,p)<<" ";
	//actual algorithm behind it
	cout<<cal_pow(n,p);
	
}
