#include<iostream>
using namespace std;
int count=0;
	void integers(){
		if(count==11){
			return;
		}else{
			cout<<count<<" ";
			count++;
			integers();
		}
	}
int main()
{
	integers();
}
