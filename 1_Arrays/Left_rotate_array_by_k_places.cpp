#include<bits/stdc++.h>
using namespace std;
void reversal(vector<int>& arr, int start, int end){
	while(start<end){
		swap(arr[start++],arr[end--]);
	}
}
void leftrotate(vector<int>& arr,int k){
	int n=arr.size();
	k=k%n;
	if (k == 0) return;
	reversal(arr,0,k-1);
	reversal(arr,k,n-1);
	reversal(arr,0,n-1);
}
int main(){
	vector<int> nums={1,2,3,4,5,6,7,8,9};
	leftrotate(nums,10);
	for(auto it : nums){
		cout<<it<<" ";
	}
	
}
