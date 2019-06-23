// insert the node-'node' in a sorted linked list //

void insert(node* head, node* node) {
	if(head == NULL || node->data < head->data){
		node->next = head;
		head = node;
		return;
	}	
	
	node* curr = head;
	while(curr->next != NULL and curr->next->data < node->data) curr = curr->next;
	
	node->next = curr->next;
	curr->next = node;
}
