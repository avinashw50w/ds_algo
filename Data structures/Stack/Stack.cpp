
int top = -1;
const int sz = 100;
int a[sz];

bool isFull() { return top == sz-1; }

bool isEmpty() { return top == -1; }

void push(int val)
{
	if(isFull())
	{
		cout << "overflow\n";
		return;
	}
	a[++top] = val;
}

void pop()
{
	if(isEmpty())
	{
		cout << "empty stack\n";
		return;
	}
	top--;
}

int top()
{
	if(isEmpty())
	{
		cout << "empty stack\n";
		return;
	}
	return a[top];
}
