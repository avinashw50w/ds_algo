/*Design and Implement Special Stack Data Structure | Added Space Optimized Version
Question: Design a Data Structure SpecialStack that supports all the stack operations like push(), pop(), isEmpty(), 
isFull() and an additional operation getMin() which should return minimum element from the SpecialStack. 
All these operations of SpecialStack must be O(1). To implement SpecialStack, you should only use standard Stack data structure 
and no other data structure like arrays, list, .. etc.

Example:

Consider the following SpecialStack
16  --> TOP
15
29
19
18

When getMin() is called it should return 15, which is the minimum 
element in the current stack. 

If we do pop two times on stack, the stack becomes
29  --> TOP
19
18

When getMin() is called, it should return 18 which is the minimum 
in the current stack.


Solution: Use two stacks: one to store actual stack elements and other as an auxiliary stack to store minimum values. 
The idea is to do push() and pop() operations in such a way that the top of auxiliary stack is always the minimum. 
Let us see how push() and pop() operations work.

Push(int x) // inserts an element x to Special Stack 
1) push x to the first stack (the stack with actual elements)
2) compare x with the top element of the second stack (the auxiliary stack). Let the top element be y.
…..a) If x is smaller than y then push x to the auxiliary stack.
…..b) If x is greater than y then push y to the auxiliary stack.

int Pop() // removes an element from Special Stack and return the removed element 
1) pop the top element from the auxiliary stack.
2) pop the top element from the actual stack and return it.

The step 1 is necessary to make sure that the auxiliary stack is also updated for future operations.

int getMin() // returns the minimum element from Special Stack 
1) Return the top element of auxiliary stack.

We can see that all above operations are O(1).
Let us see an example. Let us assume that both stacks are initially empty and 18, 19, 29, 15 and 16 are inserted to the SpecialStack.

When we insert 18, both stacks change to following.
Actual Stack
18 <--- top     
Auxiliary Stack
18 <---- top

When 19 is inserted, both stacks change to following.
Actual Stack
19 <--- top     
18
Auxiliary Stack
18 <---- top
18

When 29 is inserted, both stacks change to following.
Actual Stack
29 <--- top     
19
18
Auxiliary Stack
18 <---- top
18
18

When 15 is inserted, both stacks change to following.
Actual Stack
15 <--- top     
29
19 
18
Auxiliary Stack
15 <---- top
18
18
18

When 16 is inserted, both stacks change to following.
Actual Stack
16 <--- top     
15
29
19 
18
Auxiliary Stack
15 <---- top
15
18
18
18*/
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
};

class SpecialStack: public Stack {
	Stack min;
public:
	void push(T x) {
		if(empty()) {
			Stack::push(x);
			min.push(x);
		}
		else {
			Stack::push(x);
			T y = min.top();
			if(x < y) min.push(x);
			else min.push(y);
		}
	}

	void pop() {
		Stack::pop();
		min.pop();
	}

	T getMin() const { return min.top(); }
};

/*Space Optimized Version
The above approach can be optimized. We can limit the number of elements in auxiliary stack. 
We can push only when the incoming element of main stack is smaller than or equal to top of auxiliary stack. 
Similarly during pop, if the pop off element equal to top of auxiliary stack, remove the top element of auxiliary stack.*/

class SpecialStack: public Stack {
	Stack min;
public:
	void push(const T& x) {
		if(empty()) {
			Stack::push(x);
			min.push(x);
		}
		else {
			Stack::push(x);
			T y = min.top();
			if(x <= y) min.push(x);
		}
	}

	void pop() {
		T x = Stack::top();
		T y = min.top();

		if(x == y) min.pop();
	}

	T getMin() const { return min.top(); }
};

