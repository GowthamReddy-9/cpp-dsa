#include<iostream>
using namespace std;
//bitwise operators
int main(){
	int x=13;  //and
	int y=7;
	//13     1 1 0 1	one 0 ==0;
	//7  (&) 0 1 1 1	all 1 ==1;
	//       0 1 0 1 ==5
	cout<<(x&y)<<endl; //or
	//13     1 1 0 1   	one 1 ==1;
	//7  (|) 0 1 1 1	all 0 ==0;
	//       1 1 1 1 ==15
	cout<<(x|y)<<endl; //xor
	//13     1 1 0 1    //even no. of one's ==0;
	//7  (^) 0 1 1 1	//odd no. of one's ==1;
	//       1 0 1 0 ==10
	cout<<(x^y)<<endl; 
	//right shift
	int a=13>>2;
	//13  1 1 0 1 >> .. right two bits remove;
  	//    0 0 1 1 ==3
  	cout<<a<<endl;
  	//left shift
  	int b=13<<1;
	//13  0 1 1 0 1 << .. shift all bits left two times && last two bits ==0;
  	//    1 1 0 1 0 == 26;
  	cout<<b<<endl;
    //not 
    //  ~(13) ==~(0000....1101);
    //	all flips (1(111....0010));
    // by verifying first bit confirms it is a negative so it returns its 2's compliment;
    // (1000.....1101)+1==(1000...1110)==-14;
    cout<<(~13)<<endl;
}
