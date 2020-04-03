// delete the middle element of a linked list //

node* deleteMiddle(node* head) {
	if(head == NULL) return NULL:
	
	if(head->next == NULL) {
		delete head;
		return NULL;
	}
	
	node *slow, *fast, *prev;
	slow = fast = head;
	
	while(fast != NULL and fast->next != NULL){						
		fast = fast->next->next;
		prev = slow;
		slow = slow->next;
	}
	
	prev->next = slow->next;		// ----- prev --- slow --- C ---  ; here we have to delete slow. 
	delete slow;
}
