
struct Node {
	int data;
	Node *next;
};

Node* merge(Node *a, Node *b) {
	Node *res;

	if (!a) return b;
	if (!b) return a;

	if (a->data < b->data) {
		res = a;
		res->next = merge(a->next, b);
	}
	else {
		res = b;
		res->next = merge(a, b->next);
	}

	return res;
}

void breakIntoHalf(Node *head, Node *&a, Node *&b) {
	Node *slow = head, *fast = head;
	while (fast and fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	a = head;
	b = slow->next;
	slow->next = NULL;
}

void mergeSort(Node *&head) {
	if (!head or !(head->next)) return NULL;

	Node *h = head;
	Node *a, *b;

	breakIntoHalf(h, a, b);

	mergeSort(a);
	mergeSort(b);

	head = merge(a, b);
}