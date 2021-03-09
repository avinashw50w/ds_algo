/*Sort a k sorted doubly linked list
Given a doubly linked list containing n nodes, where each node is at most k away from its
target position in the list. The problem is to sort the given doubly linked list.
For example, let us consider k is 2, a node at position 7 in the sorted doubly linked list,
can be at positions 5, 6, 7, 8, 9 in the given doubly linked list.
*/

Node *sort(Node *head, int k) {
	Node *newHead = NULL, *tail = NULL;

	priority_queue<Node*, vector<Node*>, decltype(cmp)> q(cmp);
	auto cmp = [](auto & a, auto & b) { return a.data > b.data; };

	for (int i = 0; i <= k and head; ++i) {
		q.push(head);
		head = head->next;
	}

	while (q.size()) {
		Node *top = q.top(); q.pop();

		if (newHead == NULL) {
			newHead = top;
			newHead->prev = NULL;
			tail = newHead;
		}
		else {
			tail->next = top;
			top->prev = tail;
			tail = top;
		}

		if (head) {
			q.push(head);
			head = head->next;
		}
	}

	tail->next = NULL;
	return newHead;
}