/*eg.  10 -> 5 -> 12 -> 7 -> 11
	   |                |
	   4 -> 20 -> 13    17 -> 6
	        |     |     |
	        2 -> 16     9 -> 8
	              |     |
	              3     19 -> 15

output: 10->5->12->7->11->4->20->13->17->6->2->16->9->8->3->19->15
*/

struct Node {
	int data;
	Node *next, *down;
}

void solve(Node *head) {
	if (!head) return;

	Node *tail = head;
	while (tail->next) tail = tail->next;

	Node *curr = head;

	while (curr != tail) {
		if (curr->down) {
			tail->next = curr->down;

			Node *tmp = curr->down;
			while (tmp->next) tmp = tmp->next;

			tail = tmp;
		}

		curr = curr->next;
	}
}