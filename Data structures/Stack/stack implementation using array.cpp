const int MAXN = 1e5 + 5; // size of the stack

int top = -1; // it points to the top element of stack
int st[MAXN]; // stack

// return true if the stack is empty otherwise false
bool empty()
{
	return top == -1;
}

// returns true if the stack is full otherwise false
bool full()
{
	return top == MAXN-1;
}

// returns the top element of the stack
int top()
{
	return st[top];	
}

// push an element e into the stack
void push(int e)
{
	if(full()) 
		return;

	st[++top] = e;
}

// pop(remove) the top element of the stack
void pop()
{
	if(empty())
		return;

	--top;
}