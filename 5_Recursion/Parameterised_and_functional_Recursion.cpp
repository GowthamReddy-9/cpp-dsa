#include<iostream>
using namespace std;
void add_num(int i,int sum){  //using parameters and printing sum .
	if(i<1){
		cout<<sum;
		return;
	}else{
		add_num(i-1,sum+i);
	}
}
int add_num(int n){  //without using parameters returning sum.
	if(n==0) return 0;
	return n+add_num(n-1);
}
int fact(int n){  
	if(n==0) return 1;    //returning 1 if n==0 because 0!==1.
	return n*fact(n-1);
}

int main()
{
	int N;
	cin>>N;
	cout<<"using parameters: ";
	add_num(N,0);
	cout<<endl<<"without using parameters: ";
	cout<<(add_num(N));
	cout<<endl<<"Factorial of "<<N<<" is: "<<fact(N);
}

