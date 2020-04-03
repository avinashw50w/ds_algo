#include<iostream>
#include<sstream>
#include<string>
using namespace std;
int main(){
	string s;
	int n;
	cout<<"enter the the number :";
	cin>>s;
	stringstream(s) >> n;
	cout<<"\n 2 x n = "<<2*n;
}
