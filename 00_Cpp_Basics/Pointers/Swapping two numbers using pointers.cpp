#include<iostream>
using namespace std;
void swap(int* x,int* y)
{
	int temp;
	temp=*x;  //swapping using dereferencing.
	*x=*y;
	*y=temp;
}
int main()
{
	int a;
	int b;
	a=5; //intializing a&b.
	b=10;
	int* ptr1=&a; //storing address of a in ptr1.
	int* ptr2=&b; //storing address of b in ptr2.
	cout<<"---Printing values before swapping---"<<endl;
	cout<<"a: "<<a<<endl;
	cout<<"b: "<<b<<endl;
	swap(ptr1,ptr2);  //passing ptr1,ptr2 and calling swap function.
	cout<<"---Printing values after swapping---"<<endl;
	cout<<"a: "<<a<<endl;
	cout<<"b: "<<b<<endl;
	return 0;
}
