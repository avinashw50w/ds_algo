/*You are given a Double Link List with one pointer of each node pointing to the next node just like in a single link list. The second pointer however CAN point
to any node in the list and not just the previous node. Now write a program in O(n) time to duplicate this list. That is, write a program which will create a
copy of this list.*/

struct Node {
	int data;
	struct Node *next, *random;
}

Node *head = NULL;

Node* newNode(int data) {
	Node *tmp = new Node();
	tmp->data = data;
	tmp->next = tmp->random = NULL;
	return tmp;
}

Node* clone(Node *head) {
	Node *original = head, copy = NULL;

	map<Node*, Node*> m;

	while(original) {
		m[original] = newNode(original->data);
		original = original->next;
	}

	original = head;

	while(original != NULL) {
		copy = m[original];
		copy->next = m[original->next];
		copy->random = m[original->random];
		original = original->next;
	}

	return copy;
}
