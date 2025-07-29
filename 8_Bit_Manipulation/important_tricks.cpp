#include<bits/stdc++.h>
using namespace std;
void xor_swap(int& a, int& b){
	a=a^b;  // assume a=5,b=7 here a=5^7
	b=a^b;  // now b=a^b-->b=5^7^7-->b=5
	a=a^b;	// here a=a^b-->5^7^5-->a=7
	//swapping done
	return;
}
void check_ith_bit(int a, int i){
	// a==5 --> 1 0 1 ,i ==2 which is set
    //1<<2 -->  1 0 0 perform &
    if(a&(1<<2)!=0)cout<<"set"<<endl;
    else cout<<"Not set"<<endl;
    return;
}
int set_ith_bit(int a,int i){
	// a==9 --> 1 0 0 1 ,i ==2 
    //1<<2 -->  0 1 0 0 perform | --> 1 1 0 1 ==13;
     return a|(1<<i);
}
int clear_ith_bit(int a,int i){
	int x=~(1<<i);
	return a&x;     //ith bit -->0
}
int toggle_ith_bit(int a, int i){
	return a^(1<<i);   //0-->1 ,1-->0
}
int remove_last_set_bit(int a){
	//a==12 --> 1(1)00   a-1==11  --> 1011   ans-->1000==8;
	return a&(a-1);  
}
void checkif_power_of_2(int a){
	//power of two's has only one set bit
	//remove that it must become 0
	if((a&(a-1))==0) cout<<"True"<<endl;
	else cout<<"False"<<endl;
}
int count_1s(int n){
	int count=0;
//	while(n>0){
//		if((n&1)==1) count++;      //approach 1
//		n=n>>1;
//	}
	while(n!=0){
		n=(n&(n-1));   //better approach
		count++;
	}
	return count;
}
int main()
{
	int a=5;
	int b=7;
	xor_swap(a,b);
	cout<<"a: "<<a<<"	b: "<<b<<endl;
	check_ith_bit(a,2);
	cout<<set_ith_bit(9,2)<<endl;
	cout<<clear_ith_bit(13,2)<<endl;
	cout<<toggle_ith_bit(9,2)<<endl;
	cout<<toggle_ith_bit(13,2)<<endl;
	cout<<remove_last_set_bit(12)<<endl;
	checkif_power_of_2(16);
	cout<<count_1s(13)<<endl; //3 in this case
}
