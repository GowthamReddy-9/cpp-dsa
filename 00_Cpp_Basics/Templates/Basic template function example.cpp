#include<iostream>
using namespace std;
template <typename T> //creating a template named T it actully a place holder of datatype
T getmax(T a, T b)
{
	return (a>b)?a:b;
}
int main()
{
	cout<<getmax(10,15)<<endl; //works with int.
	cout<<getmax(11.5,15.1)<<endl; //works with float.
	cout<<getmax('a','c')<<endl; //works with char.
}
