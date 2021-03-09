struct Node {
	int data;
	Node *next;
};

class Queue {
	Node *front, *rear;

public:

	Queue();

	void push(int );

	void pop();

	int top() const { return front->data; }

	bool empty() const { return front == rear; }
}

Queue::Queue() {
	front = rear = NULL;
}

void Queue::push(int x) {

	Node *tmp = new Node();

	tmp->data = x;
	tmp->next = NULL;

	if (front == NULL)
		front = rear = tmp;
	else
		rear->next = tmp;

	rear = tmp;
}

void Queue::pop() {
	if (front == NULL) return;

	Node *tmp = front;
	front = front->next;
	delete tmp;
}

