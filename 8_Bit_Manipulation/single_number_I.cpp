#include<bits/stdc++.h>
//find the number appears once,and the others twice.
using namespace std;
int appearOnce(vector<int>& nums){
	int xor1=0;       
	 //X^X=0; X^0=X;
	for(int i=0; i<nums.size(); i++){ 
	//the numbers repeated twice will become 0 at end its left xor1=3^0=3;
		xor1=xor1^nums[i];
	}
	return xor1;
}
int main(){
	vector<int> arr={1,1,2,3,2,5,5};
	cout<<appearOnce(arr);
}
