#include<bits/stdc++.h>
using namespace std;
void transpose(vector<vector<int>>& matrix ,int n){
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			swap(matrix[i][j],matrix[j][i]);
		}
	}
}
void rotate(vector<vector<int>>& matrix ,int n){
	transpose(matrix,n);
	for(int i=0; i<n; i++){
		reverse(matrix[i].begin(),matrix[i].end());
	}
}

int main(){
	vector<vector<int>> matrix;
	int n=4;
	vector<int> row1={1,2,3,4};
	vector<int> row2={5,6,7,8};
	vector<int> row3={9,10,11,12};
	vector<int> row4={13,14,15,16};
	vector<int> row0={0,0,0,0};
	matrix.push_back(row1);
	matrix.push_back(row2);
	matrix.push_back(row3);
	matrix.push_back(row4);
	rotate(matrix,n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<matrix[i][j]<<"  ";
		}
		cout<<endl;
		cout<<endl;
	}
}
