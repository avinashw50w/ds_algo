void reverse(Node *&head) {
	Node *curr = head, *prev = NULL;

	while (curr) {
		Node *next = curr->next;
		curr->prev = next;
		curr->next = prev;

		prev = curr;
		curr = next;
	}

	head = prev;
}

// recursive
void solve(Node *prev, Node *curr, Node *&head) {
	if (!curr->next) {
		curr->prev = NULL;
		curr->next = prev;
		head = curr;
		return;
	}

	Node *next = curr->next;
	curr->prev = next;
	curr->next = prev;

	reverse(curr, next, head);
}

void reverse(Node *head) {
	solve(head->prev, head, head);
}