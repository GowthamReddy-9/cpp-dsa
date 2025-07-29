#include<bits/stdc++.h>
using namespace std;
int count_digits(int n){
	return (int)log10(n)+1; //one way to count no. of digits.
}
bool check_palindrome(int n){
	if(n<0) return false; //negatives or not palindromes.
	if(n>=0&&n<=9) return true; //single digits or always palindromes.
	int x=n; //we need n to compare .
	int reverse=0;
	while(x>0){
		reverse=(reverse*10)+(x%10); //when x divided by 10 remainder should be last digit,
		x=x/10;  //we can add a counter here and increment it to count no. of digits.
	}
	if(reverse==n) return true;
	return false;	
}
int main(){
	int n;
	cout<<"Input: ";
	cin>>n;
	if(check_palindrome(n)){
		cout<<endl<<n<<" is a palindrome";
	}else{
		cout<<endl<<n<<" is not a palindrome";
	}
	cout<<endl<<"Total digits: "<<count_digits(n);
}
