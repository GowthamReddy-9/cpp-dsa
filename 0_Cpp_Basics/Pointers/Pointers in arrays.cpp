#include<iostream>
using namespace std;
void reverse_array(int* a,int n) //declaring and defining a function that takes address of first value and array
{                                   //as input and reverse it.
	for(int i=0; i<=n/2; i++)
	{
		int temp=*(a+i);
		*(a+i)=*(a+n-i-1);
		*(a+n-i-1)=temp;
	}
}
int main()
{
int arr[5]={1,2,3,4,5};
int* ptr=arr; //the name of the array(arr) actually stores the addres of value at arr[0].
cout<<"[1]. ptr&arr points to same address --> "<<ptr<<":"<<arr<<endl;
cout<<"[2]. ptr+4&arr+4 points to same address --> "<<ptr+4<<":"<<arr+4<<endl;
cout<<"[3]. *(ptr+i)&*(arr+i)&arr[i] prints same value at index i --> "<<*(ptr+1)<<":"<<*(ptr+1)<<":"<<arr[1]<<endl;
//accessing values at index i using dereferencing in arrays *(arr+i) equals to arr[i].
cout<<"---Printing Array Before Swapping---"<<endl;
for(int i=0; i<5; i++)
{
	cout<<arr[i]<<" ";
}
cout<<endl;
reverse_array(arr,5);  //calling function for reversing array.
cout<<"---Printing Array After Swapping---"<<endl;
for(int i=0; i<5; i++)
{
	cout<<arr[i]<<" ";
}
cout<<endl;
return 0;
}
