template<typename T>
class Queue {
	T *A;
	int front, rear, sz;

public:
	Queue(int );

	void push(T );

	void pop();

	T top const { return A[front]; }

	bool full() { return rear == sz; }

	bool empty() { return front == rear; }
}

Queue::Queue(int c) {
	sz = c;
	A = new T[c];
	front = rear = -1;	
}

void Queue::push(T val) {
	if(full()) return;
	A[++rear] = val; 
}

void Queue::pop() {
	if(empty()) return;
	++front;
}

