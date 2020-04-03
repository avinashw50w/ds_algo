//  check if a linked list is circular //

int check(node* head) {
	if(head == NULL) return true;
	
	node* curr = head;
	
	while(curr != NULL and curr != head) curr = curr->next;
	
	return ( curr == head );
}

// another method
bool check (Node *head) {
	if (head == NULL or head->next == NULL) return false;
	Node *slow = head, *fast = head;

	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast) return true;
	}

	return false;
}
