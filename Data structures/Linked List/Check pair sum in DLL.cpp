/*Find pairs with given sum in doubly linked list
Last Updated: 06-06-2020
Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in doubly linked list whose sum is equal to given value x, without using any extra space ?
Example:

Input : head : 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
        x = 7
Output: (6, 1), (5,2)*/

bool check(Node *head, int x) {
	if (!head) return false;
	Node *l = head, *r = head;
	while (r->next) r = r->next;

	while (l != r and l != r->next) {
		if (l->data + r->data == x) return true;
		if (l->data + r->data < x) l = l->next;
		else r = r->prev;
	}

	return false;
}