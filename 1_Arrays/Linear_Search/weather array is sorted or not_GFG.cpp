// Problem: Check if Array is Sorted
// GFG Link: https://www.geeksforgeeks.org/problems/check-if-an-array-is-sorted0701/1
// Time: O(n), Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

bool isSortedNonDecreasing(vector<int>& arr) {
	bool increasing = true;     
	bool decreasing = true;
    for (int i = 0; i < arr.size() - 1; i++) {   //looping i until size-2 to avoid overflow error while i+1. 
        if (arr[i] > arr[i + 1]) {
            increasing=false;       //check weather it is decreasing order or not.
        }
        if (arr[i] < arr[i + 1]) {
            decreasing=false;       // check weather it is increasing or not.
        }
    }
    return increasing || decreasing;  // return true if any of them true.
}

int main() {
	vector<int> arr;
    int n;
    cout<<"Enter size of array: "<<endl;
    cin>>n;
    for(int i=0; i<n; i++){
    	int value;
    	cout<<"Enter value: "<<endl;
    	cin>>value;
    	arr.push_back(value);
	}
    cout << (isSortedNonDecreasing(arr) ? "Sorted" : "Not Sorted");
    return 0;
}

