#include<iostream>
using namespace std;
void by_value(int x)
{
	x=x+10;
	cout<<"--Pass by Value--."<<endl;
	cout<<"a: "<<x<<endl; //updating value of an variable using pass by value
}
void by_reference(int* x)
{
	*x=*x+10;
	cout<<"--Pass by Reference--."<<endl;
	cout<<"a: "<<*x<<endl; //updating value of an variable using pass by reference
}
int main()
{
	int a=5;
	by_value(a);
	cout<<"The value of 'a' after calling function using pass by value"<<endl;
	cout<<"a: "<<a<<endl;
	by_reference(&a);
	cout<<"The value of 'a' after calling function using pass by reference"<<endl;
	cout<<"a: "<<a<<endl;


}
