#include <iostream>
using namespace std;

void reverse(string &str, int index, int size){
	if(index == size/2) return;
	swap(str[index], str[size-index-1]);
	reverse(str,index+1,size);
}

int main(){
	string str = "avinash";
	reverse(str,0,str.size());
	cout<<str;
}