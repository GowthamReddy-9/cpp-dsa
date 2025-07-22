#include<bits/stdc++.h>
using namespace std;
//return the value in pascal triangle at pos [row][col]
long long return_element(int row, int col){  
	int n=row-1;
	int r=col-1;       //shortcut to calculate value in pascal triangle [row-1] combination [col-1]
	long long ans=1;   //n! might be larger value to avoid overflow.
	for(int i=1; i<=r; i++){
		ans=ans*n;
		ans=ans/i;
		n=n-1;
	}
	return ans;
}
void return_row(vector<int>& row,int n){
	int ans=1;
	row.push_back(ans);
	for(int i=1; i<n; i++){
		ans=ans*(n-i);
		ans=ans/i;
		row.push_back(ans);
	}
	return;
}
void pascal_triangle(vector<vector<int>>& ans,int n){
	for(int i=1; i<=n; i++){
		vector<int> temp;
		return_row(temp,i);
		ans.push_back(temp);
	}
}
int main()
{
long long k=return_element(5,3);
cout<<k<<endl;
vector<int> row;
return_row(row,5);
for(int i=0; i<5; i++){
	cout<<row[i]<<" ";
}
cout<<endl;
vector<vector<int>> ans;
int m=5;
pascal_triangle(ans,m);
for(int i=0; i<m; i++){
	for(int k=1; k<=m-i-1; k++){  //for spaces.
			cout<<" ";
		}
	for(int j=0; j<ans[i].size(); j++){
		cout<<ans[i][j]<<" ";
	}
	cout<<endl;
}

}
