#include<bits/stdc++.h>
using namespace std;
void set_zeros(vector<vector<int>>& matrix, int n, int m){
	int col0=1;
	for(int i=0; i<n; i++){
		for(int j=1; j<m; j++){
			if(matrix[i][j]==0){
				matrix[i][0]=0;
				if(j==0){
					col0=0;
				}else{
					matrix[0][j]=0;
				}
			}
		}
	}
	for(int i=1; i<n; i++){
		for(int j=0; j<m; j++){
			if(matrix[0][j]==0||matrix[i][0]==0) matrix[i][j]=0;
		}
	}
	if(matrix[0][0]==0){
		for(int j=0; j<m; j++){
			matrix[0][j]=0;
		}	
	}
	if(col0==0){
		for(int i=0; i<n; i++){
			matrix[i][0]=0;
		}	
	}
	
	
}
int main(){
	vector<vector<int>> matrix;
	int n=4;
	int m=4;
	vector<int> row1={1,1,1,1};
	vector<int> row2={1,0,1,1};
	vector<int> row3={1,1,0,1};
	vector<int> row4={1,1,1,1};
	matrix.push_back(row1);
	matrix.push_back(row2);
	matrix.push_back(row3);
	matrix.push_back(row4);
	set_zeros(matrix,n,m);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout<<matrix[i][j]<<"  ";
		}
		cout<<endl;
		cout<<endl;
	}
}
