/*input : 1->2->4->3->6->8
 output : 2->4->6->6->1->3  */

void segregate(Node *head) {

	Node *curr = head, *evenHead = NULL, *oddHead = NULL, *evenEnd = NULL, *oddEnd = NULL;

	while (curr != NULL) {
		if (curr->data % 2 == 0) {
			if(evenHead == NULL) 
				evenHead = evenEnd = curr;
			else {
				evenEnd->next = curr;
				evenEnd = curr;
			}
		}

		else {
			if(oddHead == NULL)
				oddHead = oddEnd = curr;
			else {
				oddEnd->next = curr;
				oddEnd = curr;
			}
		}
		
		curr = curr->next;
	}

	evenEnd->next = oddHead;
}