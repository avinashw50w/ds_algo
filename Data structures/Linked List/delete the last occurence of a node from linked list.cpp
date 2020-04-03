
void deleteLastOccurence(Node *head, int key) {
	Node *x = NULL, *tmp = head;

	while(tmp) {
		if(tmp->key == key) x = tmp;

		tmp = tmp->next;
	}

	if(x != NULL) {
		tmp = x->next;
		x->key = tmp->key;
		x->next = tmp->next;
		free(tmp);
	}
}