#include<bits/stdc++.h>
using namespace std;
void maxHeapify(vector<int>& nums,int n,int i){
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n&&nums[l]>nums[largest]) largest=l;
	if(r<n&&nums[r]>nums[largest]) largest=r;
	if(largest!=i){
		swap(nums[largest],nums[i]);
		maxHeapify(nums,n,largest);
	}
}
void heapSort(vector<int>& nums,int n){
	//Convert to max heap first;
	for(int i=(n-2)/2; i>=0; i--){
		maxHeapify(nums,n,i);
	}
	for(int i=n-1; i>0; i--){
		swap(nums[0],nums[i]);
		maxHeapify(nums,i,0);
	}
}
int main(){
	vector<int> nums = {3, 1, 4, 1, 5, 9};
	heapSort(nums,nums.size());
	for(int i:nums) cout<<i<<" ";
}
