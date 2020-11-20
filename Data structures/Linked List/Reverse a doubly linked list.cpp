void reverse(Node *&head) {
	Node *curr = head, *prev = NULL;

	while (curr) {
		prev = curr->prev;
		curr->prev = curr->next;
		curr->next = prev;

		prev = curr;
		curr = curr->prev;
	}
	if (prev) head = prev;
}

// recursive
void swap(Node *node) {
	Node *prev = node->prev;
	node->prev = node->next;
	node->next = prev;
}
void reverse(Node *&head, Node *curr) {
	if (!curr->next) {
		swap(curr);
		head = curr;
		return;
	}

	swap(curr);
	reverse(head, curr->prev);
}