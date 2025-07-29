#include<bits/stdc++.h>
using namespace std;
bool armstrong(int n){
	if(n<0) return false; //ignoring negatives.
	if(n>=0&&n<=9) return true; 
	int x=n; 
	int cube_sum=0;
	while(x>0){
		int last_digit=x%10;
		cube_sum=cube_sum+(last_digit*last_digit*last_digit);
		x=x/10; 
	}
	if(cube_sum==n) return true;
	return false;	
}
int main(){
	vector<int> nums = {153, 370, 100, 947, 371, 200};
	for(auto it:nums){
		if(armstrong(it)){
			cout<<endl<<it<<" is a armstrong.";
		}else{
			cout<<endl<<it<<" is not a armstrong.";
		}
	}
	return 0;
}
