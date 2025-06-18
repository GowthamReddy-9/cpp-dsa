#include<iostream>
#include<string>
using namespace std;
template <typename T1, typename T2>   //two templates T1,T2.
class Pair
{
	private:
		T1 age;       
		T2 name;
	public:
		void get(T1 a, T2 b)
		{      //intializing age,name in public member function to access outside class.
			age=a;
			name=b;
		}
		void print()
		{
			cout<<name<<" is "<<age<<" years old"<<endl; 
		}
		
};
int main()
{
	Pair<int,string> p1;    //we have to explicitly replace T1,T2 to required type while creating object.
	p1.get(10,"Gowtham");
	p1.print();
}
