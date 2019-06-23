//  check if a linked list is circular //

int check(node* head) {
	if(head == NULL) return true;
	
	node* curr = head;
	
	while(curr != NULL and curr != head) curr = curr->next;
	
	return ( curr == head );
}
