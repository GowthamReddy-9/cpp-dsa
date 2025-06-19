#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> v(2,3);    //Declaring an vector array of size 2 and intializing all values with 3
	cout<<"Printing Array Before Push_back"<<endl;
	for(int i=0; i<v.size(); i++){    
		cout<<v[i]<<" ";
	}
	cout<<endl;
	v.push_back(4);
	v.push_back(5);     //adding new values to array.
	cout<<"Printing Array After Push_back"<<endl;
	for(int i=0; i<v.size(); i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	cout<<"Printing Array After Pop_back"<<endl;
	v.pop_back();     //removing last value.
	for(int i=0; i<v.size(); i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	v.reserve(6);    //here it allocates memory for 6 integers but size of vector does'nt change.
	cout<<"Size: "<<v.size()<<" Capacity: "<<v.capacity()<<endl;
	//capacity-->memory allocated,size-->current size of total elements in vector
	v.shrink_to_fit();  //now it shrinks allocated memory.
	cout<<"Size: "<<v.size()<<" Capacity: "<<v.capacity()<<endl;
	v.resize(6); //here changes size and intializes remaining elements to '0'.
	cout<<"Size: "<<v.size()<<" Capacity: "<<v.capacity()<<endl;
	cout<<"Printing array using auto iterator"<<endl;
	for(auto it=v.begin(); it!=v.end(); it++){
		cout<<*it<<" ";
	}
	
	
}
