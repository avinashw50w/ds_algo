#include<iostream>
using namespace std;
template<class T>
class Stack{
	int t,sz;
	T *arr;
	public: Stack(int c): sz(c) , t(-1)  { arr=new T[c];};
	void push(T x){
		if(t==sz-1) return;
		arr[++t] = x;
	}
	void pop(){
		if(t==-1){ cout<<"Empty stack\n"; return;}
		t--;
	}
	T top(){
		return arr[t];
	}
	bool empty(){
		return t==-1;
	}
	void print(){
		for(int i=0;i<=t;i++)
		cout<<arr[i]<<" ";
		cout<<endl;
	}
};
int main(){
	Stack<char> s(20);
	char str[15];
	scanf("%s",str);
	int i=0;
	while(str[i]!='\0') s.push(str[i]),i++;
	while(!s.empty()) cout<<s.top(), s.pop();
	
	return 0;
}
// time and space complexity : O(n)

/* use this for O(1) space
for(int i=0,j=str.size()-1;i!=j;i++,j--) swap(str[i],str[j]);
*/
