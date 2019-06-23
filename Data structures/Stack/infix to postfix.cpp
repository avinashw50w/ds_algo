#include<iostream>
#include<ctype.h>
#include<string.h>
using namespace std;
template<typename T>
class Stack{
	int t,sz;
	T *arr;
public: 
	Stack(int c): sz(c) , t(-1)  { arr = new T[c]; }
	
	bool full() const { return t == sz-1; }
	
	bool empty() const { return t == -1; }
	
	void push(T x){
		if (full()) return;
		arr[++t] = x;
	}
	
	void pop(){
		if (empty()) return;
		t--;
	}
	
	T top() const { return arr[t]; }

};

int prec(char a){
	switch(a){
		case '-': case '+': return 0; break;
		case '*': case '/': return 1; break;
		case '^': return 2; break;
	}
	return -1;
}
int main(){
	Stack<char> s(20);

	string infix, postfix = "";
	
	cout<<"\nEnter the infix expression:";
	cin>>infix;
	
	for(int i = 0; i < infix.length(); i++){
		
		if(infix[i]>='a' && infix[i]<='z') postfix += infix[i];
		
		else if (infix[i] == '(') s.push(infix[i]);
		
		else if (infix[i] == ')'){
			while(!s.empty() and s.top() != '('){
				postfix += s.top();
				s.pop();
			}
			if(s.empty()) return -1;
			s.pop();
		}
		else{
			while (!s.empty() and prec(s.top()) > prec(infix[i])){
				postfix += s.top();
				s.pop();
			}
			s.push(infix[i]);
		}
	}
	while(!s.empty()){
		postfix += s.top();
		s.pop();
	}
	
	cout<<postfix<<endl;
	
	return 0;
}
