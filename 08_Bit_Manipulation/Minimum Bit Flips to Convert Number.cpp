#include<bits/stdc++.h>
using namespace std;
int count_flips(int val, int goal){
	int x=(val^goal);
	int c=0;
	while(x!=0){
		if((x&1)==1) c++;
		x=x>>1;
	}
	return c;
}
int main ()
{
	int val=10;  //01010
	int goal=17; //10001
	//answer 4 flips
	cout<<"Required flips: "<<count_flips(val,goal)<<endl;
}
