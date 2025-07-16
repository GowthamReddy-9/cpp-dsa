#include<bits/stdc++.h>
using namespace std;
int second_max(vector<int>& nums){
	if(nums.size()<=1) return INT_MIN; 
	int max1=nums[0];
	int max2=INT_MIN;
	for(int i=1; i<nums.size(); i++){
		if(nums[i]>max1){
			max2=max1;
			max1=nums[i];
		}else if(nums[i]<max1&&nums[i]>max2){
			max2=nums[i];
		}
	}
	return max2;
}
int main(){
	vector<int> a={23,23,1,2,19,14,6};
	int Max2=second_max(a);
	(Max2==INT_MIN)?cout<<"Second Max Does'nt exist":cout<<Max2;
	
}
