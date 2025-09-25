#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct Book
{
	string title;               //creating an user defined datatype Book using Struct.
	int pages;
	Book(int a, string b){
		title=b;
		pages=a;                 //using constructer to intialize title,pages.
	}
};
int main()
{
	vector<Book> v;
	v.emplace_back(200,"Manga 1");      
	v.emplace_back(500,"Manga 2");
	v.emplace_back(600,"Manga 3");
	for(int i=0; i<v.size(); i++){
		cout<<v[i].title<<" has "<<v[i].pages<<" pages."<<endl;
	}
}

