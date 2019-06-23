#include<iostream>
using namespace std;
template<typename T>
class Stack {
	int t, sz;
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
	
	void print(){
		for(int i=0;i<=t;i++)
		cout<<arr[i]<<" ";
		cout<<endl;
	}
};
/////////////////////////////////////////////////////
template<class T>
class stack{
vector<int> mystack;
public:
	void push(T const& elem){
		mystack.push_back(elem);
	}
	void pop(){
		if(mystack.empty())
		throw out_of_range("\nEmpty stack");

		mystack.pop_back();
	}
	T top() const{
		if(mystack.empty())
		throw out_of_range("\nEmpty stack");

		return mystack.back();
	}
	
	bool empty() const{ return mystack.empty();  }
};

