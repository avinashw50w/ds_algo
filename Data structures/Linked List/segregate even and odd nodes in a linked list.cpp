/*input : 1->2->4->3->6->8
 output : 2->4->6->6->1->3  */

void segregate(Node *head) {

	Node *curr = head, *evenHead = NULL, *oddHead = NULL, *lastEven = NULL, *lastOdd = NULL;

	while (curr != NULL) {
		if (curr->data % 2 == 0) {
			if(evenHead == NULL) 
				evenHead = lastEven = curr;
			else {
				lastEven->next = curr;
				lastEven = curr;
			}
		}

		else {
			if(oddHead == NULL)
				oddHead = lastOdd = curr;
			else {
				lastOdd->next = curr;
				lastOdd = curr;
			}
		}
		
		curr = curr->next;
	}

	lastEven->next = oddHead;
}