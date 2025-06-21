#include<iostream>
#include<vector>
//https://leetcode.com/problems/reverse-string/description/
using namespace std;
 void reverseString(vector<char>& s) {
        for(int i=0; i<s.size()/2; i++){
                char temp;
                temp=s[i];
                s[i]=s[s.size()-1-i];
                s[s.size()-1-i]=temp;

        }
    }
int main(){
	vector<char> arr;
    int n;
    cout<<"Enter size of array: "<<endl;
    cin>>n;
    for(int i=0; i<n; i++){
    	char value;                       
    	cout<<"Enter char: "<<endl;
    	cin>>value;
    	arr.push_back(value);
	}
	cout<<"Printing String Before Reversing: "<<endl;
    for(int i=0; i<arr.size(); i++){
    	cout<<arr[i]<<" ";
	}
	cout<<endl;
	cout<<"Printing String After Reversing: "<<endl;
	reverseString(arr);
    for(int i=0; i<arr.size(); i++){
    	
    	cout<<arr[i]<<" ";
	}
    return 0;
}

