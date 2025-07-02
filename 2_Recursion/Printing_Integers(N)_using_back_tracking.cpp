#include<iostream>
using namespace std;
	void integers(int i,int N){
		if(i<1){                    //base case.
			return;
		}else{
			integers(i-1,N);        //printing output after calling function.
			cout<<i<<" ";           //this line only excutes if base case is true.
		}
	}
int main()
{
	int N;
	cin>>N;
	integers(N,N);
}
̥