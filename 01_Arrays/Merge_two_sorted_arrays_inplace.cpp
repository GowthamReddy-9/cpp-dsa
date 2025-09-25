#include <bits/stdc++.h>
using namespace std;
//Helper function
void swapIfGreater(vector<int>& arr1,vector<int>& arr2,int ind1,int ind2){
	if(arr1[ind1]>arr2[ind2]) swap(arr1[ind1],arr2[ind2]);
}
//Gap method
void GapMethod(vector<int>& arr1,vector<int>& arr2){
	int n=arr1.size();
	int m=arr2.size();
	int length=m+n;
	int gap=(length/2)+(length%2);
	while(gap>0){
		int left=0;
		int right=left+gap;
		while(right<length){
			if(left<n&&right>=n){
				swapIfGreater(arr1,arr2,left,right-n);
			}else if(left>=n){
				swapIfGreater(arr2,arr2,left-n,right-n);
			}else{
				swapIfGreater(arr1,arr1,left,right);
			}
			left++;
			right++;
		}
		if(gap==1) break;
		gap=(gap/2)+(gap%2);
	}
}
//compare and sorting
void compare_sort(vector<int>& arr1,vector<int>& arr2){
	int n=arr1.size();
	int m=arr2.size();
	int right=n-1;
	int left=0;
	while(left<n&&right>=0){
		if(arr1[right]>arr2[left]){
			swap(arr1[right],arr2[left]);
			left++;
			right--;
		}else{
			break;
		}
		
	}
	sort(arr1.begin(),arr1.end());
	sort(arr2.begin(),arr2.end());
}
void printArray(const vector<int>& arr) {
    for (int x : arr) cout << x << " ";
}
// ------------------- Main Test Function -------------------
int main() {
    vector<int> a1 = {1, 4, 7, 8, 10};
    vector<int> b1 = {2, 3, 9};
	GapMethod(a1,b1);
	cout<<"a1,b1 after sorting --> ";
	printArray(a1);
	cout<<" ";
	printArray(b1);
	cout<<endl;
    vector<int> a2 = {5, 6, 12};
    vector<int> b2 = {1, 9, 10};
	compare_sort(a2,b2);
	cout<<"a2,b2 after sorting --> ";
	printArray(a2);
	cout<<" ";
	printArray(b2);
	cout<<endl;
    return 0;
}

