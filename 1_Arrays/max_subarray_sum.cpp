#include<bits/stdc++.h>
using namespace std;
int longest_sub_arr_sum(vector<int>& nums,int k){
	int sum=nums[0];
	int n=nums.size();
	int left=0;
	int right=0;
	int max_len=0;
	while(right<n){
		while(left<=right&&sum>k){
			sum-=nums[left];
			left++;
		}
		if(sum==k){
			max_len=max(max_len,right-left+1);
		}
		right++;
		if(right<n) sum+=nums[right];
	}
	return max_len;
}
int main()
{
	vector<int> arr={1,2,3,1,0,1,1,4,2,3};
	int k=2;
	cout<<longest_sub_arr_sum(arr,k);
}
