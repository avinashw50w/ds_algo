
struct Node {
	int data;
	struct Node *prev, *next;
};

class Stack {
	Node *head, *mid;
	int count;

public:
	Stack(): head(NULL), count(0) {}

	void push(int );

	void pop();

	int findMiddle();

	void deleteMiddle();
};

void Stack::push(int val) {
	Node *newNode = new Node();

	newNode->data = val;
	newNode->prev = NULL;
	newNode->next = head;

	count += 1;

	if(count == 1) mid = newNode;

	else {
		head->prev = newNode;
		if(count & 1) mid = mid->prev;
	}

	head = newNode;
}

void Stack::pop() {
	if(count == 0) return;

	Node *tmp = head;
	head = head->next;

	if(head) head->prev = NULL;

	count--;

	if(!(count & 1)) mid = mid->next;

	delete tmp;
}

int Stack::findMiddle() {
	if(count == 0) return -1;

	return mid->data;
}

void Stack::deleteMiddle() {
	if(!count) return;

	if(count == 1) {
		head = NULL;
		mid = NULL;
		count--;
		return;
	}

	Node *tmp = mid->prev;
	tmp->next = mid->next;
	
	count--;

	if(!(count & 1)) mid = mid->next;
	else mid = tmp;

	delete mid;
}
