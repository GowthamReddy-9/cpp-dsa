#include<bits/stdc++.h>
using namespace std;

//1)brute approach  --> tracking frequency of each element

/*int single_element(vector<int>& nums){
	map<int,int> freq;
	for(int i=0; i<nums.size(); i++){
		freq[nums[i]]++;
	}
	for(auto it : freq){
		if(it.second==1) return it.first;
	}
} */

//2)using bits
 
/*int single_element(vector<int>& nums){
	int ans=0;
	for(int i=0; i<31; i++){
		int count=0;
		for(int j=0; j<nums.size(); j++){
			if((nums[j]&(1<<i))) count++;
		}
		if((count%3)!=0) ans=ans|(1<<i);
	}
	return ans;
} */

//3)better approach

/*int single_element(vector<int>& nums){
	//lets assume answer must exist
	int n=nums.size();
	sort(nums.begin(),nums.end());
	for(int i=1; i<n; i+=3){
		if(nums[i]!=nums[i-1]) return nums[i-1];
	}
	return nums[n-1];
}*/

//4)using buckets --> optimal

int single_element(vector<int>& nums){
	int ones=0;
	int twos=0;
	int n=nums.size();
	for(int i=0; i<n; i++){
		ones=(ones^nums[i])&(~twos);
		twos=(twos^nums[i])&(~ones);
	}
	return ones;
}

int main()
{
	vector<int> nums={3,5,2,5,2,3,2,3,6,5};
	cout<<single_element(nums);
}

