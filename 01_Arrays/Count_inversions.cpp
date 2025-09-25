#include<bits/stdc++.h>
using namespace std;
int merge(vector<int>& arr,int low,int mid,int high){
	int left=low;
	int right=mid+1;
	int count=0;
	vector<int> temp;
	while(left<=mid&&right<=high){
		if(arr[left]<arr[right]){
			temp.push_back(arr[left++]);
		}else{
			count+=mid-left+1;
			temp.push_back(arr[right++]);
		}
	}
	while(left<=mid){
		temp.push_back(arr[left++]);
	}
	while(right<=high){
		temp.push_back(arr[right++]);
	}
	for(int i=low; i<=high; i++){
		arr[i]=temp[i-low];
	}
	return count;
}
int merge_sort(vector<int>& arr,int low,int high){
	int count=0;
	if(low>=high) return count;
	int mid=(low+high)/2;
	count+=merge_sort(arr,low,mid);
	count+=merge_sort(arr,mid+1,high);
	count+=merge(arr,low,mid,high);
	return count;
}
int main()
{
	vector<int> arr = {8, 4, 2, 1}; 
    int result = merge_sort(arr, 0, arr.size() - 1);
    cout << "Number of inversions: " << result << endl;
    return 0;
}
