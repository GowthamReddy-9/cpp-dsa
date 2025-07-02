#include<iostream>
using namespace std;
void swap(int arr[],int l,int r){
	if(l>=r){
		return;
	}else{
		int temp=arr[l];
		arr[l]=arr[r];
		arr[r]=temp;
		swap(arr,l+1,r-1);
	}
}
int main(){
	int n;
	cout<<"enter size of array: ";
	cin>>n;
	cout<<endl;
	int a[n];
	for(int i=0; i<n; i++){
		cout<<"enter element at index "<<i<<": ";
		cin>>a[i];
		cout<<endl;
	}
	cout<<"--Before Reversing--"<<endl;
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	swap(a,0,n-1);
	cout<<"--After Reversing--"<<endl;
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
}

