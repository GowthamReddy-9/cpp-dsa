#include<bits/stdc++.h>
using namespace std;
bool check_balanced_parenthesis(string s){
	int n=s.size();
	stack<char> st;
	for(int i=0; i<n; i++){
		if(s[i]=='('||s[i]=='['||s[i]=='{') st.push(s[i]);
		else{
			if(st.empty()) return false;
			else{
				if(s[i]==')'){
					char c=st.top();
					st.pop();
					if(c!='(') return false;
				}else if(s[i]==']'){
					char c=st.top();
					st.pop();
					if(c!='[') return false;
				}else{
					char c=st.top();
					st.pop();
					if(c!='{') return false;
				}
			}
		}
	}
	return st.empty();
}
int main()
{
	vector<string> s={"(){[]()}","()[{}(])","()","{}","[]","((()","()}}"};
	for(auto it:s){
		cout<<it<<": ";
		if(check_balanced_parenthesis(it)){
			cout<<"true"<<endl;
		}else{
			cout<<"false"<<endl;
		}
	}
}
