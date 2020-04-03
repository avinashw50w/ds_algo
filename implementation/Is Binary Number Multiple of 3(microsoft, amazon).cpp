/*Given a binary number,  write a program that prints 1 if given binary number is a multiple of 3.  
Else prints 0. The given number can be big upto 2^100

It is recommended to finish the task using one traversal of input binary string.

Input:
The first line contains T denoting the number of testcases. Then follows description of testcases. 
Each case contains a string containing 0's and 1's.*/

#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	string s;
	while(t--) {
	    cin>>s;
	    int t = 0;
	    for(int i = 0; i < s.size(); ++i) {
	        t = t*2 + s[i]-'0';
	        t %= 3;
	    }
	    cout << (t == 0)? 1 : 0;
	    cout << endl;
	}
	return 0;
}