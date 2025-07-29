#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> power_set(vector<int>& nums){
	vector<vector<int>> ans;
	int n=nums.size();
	int subsets=1<<n;
	for(int i=0; i<subsets; i++){
		vector<int> temp;
		for(int j=0; j<n; j++){
			if((i&(1<<j))!=0) temp.push_back(nums[j]);
		}
		ans.push_back(temp);
	}
	return ans;
}
int main()
{
	vector<int> nums={1,2,3,4};
	vector<vector<int>> ans=power_set(nums);
	cout<<"[ ";
	for(int i=0; i<ans.size(); i++){
		cout<<"[";
		for(int j=0; j<ans[i].size(); j++){
			cout<<ans[i][j];
			if(j!=ans[i].size()-1) cout<<",";
		}
		cout<<"]";
		if(i!=ans.size()-1) cout<<",";
	}
	cout<<" ]";
}
