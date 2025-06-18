#include<iostream>
using namespace std;
int main()
{
	int a=5;
	int* p=&a;
	cout<<"The value of a: "<<a<<endl;  //prints the value that stored in 'a'.
	cout<<"The address of a: "<<&a<<endl;  //prints the address of 'a'.
	cout<<"The value of p: "<<p<<endl;  //prints the address that stored in pointer 'p'.
	cout<<"The value at address p points to: "<<*p<<endl;  //prints the value at address where pointer 'p' points to, called dereferencing.
	return 0;
}
