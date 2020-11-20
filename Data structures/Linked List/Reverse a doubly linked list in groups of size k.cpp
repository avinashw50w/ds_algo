/*reverse a doubly linked list in groups of size k*/

void push(Node *&head, Node *node) {
	node->prev = NULL;
	node->next = head;
	if (head) head->prev = node;
	head = node;
}

Node *reverse(Node *head, int k) {
	Node *curr = head, *newHead = NULL;
	int cnt = 0;

	while (curr and cnt < k) {
		push(newHead, curr);
		curr = curr->next;
		cnt++;
	}

	if (curr) {
		head->next = reverse(curr, k);
		head->next->prev = head;
	}

	return newHead;
}