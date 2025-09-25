// Problem: Find the Largest Element in an Array
// GFG Link: https://www.geeksforgeeks.org/problems/largest-element-in-array4009/1
// Time: O(n), Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

int findLargestElement(vector<int>& arr) {
    int maxVal = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > maxVal) {                //i used linear search here.
            maxVal = arr[i];
        }
    }

    return maxVal;
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
    cout << "Largest Element: " << findLargestElement(arr);
    return 0;
}

