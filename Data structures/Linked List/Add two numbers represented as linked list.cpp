/*Add two numbers represented by linked lists | Set 1
Given two numbers represented by two lists, write a function that returns sum list. The sum list is list representation of addition of two input numbers.

Example 1

Input:
  First List: 5->6->3  // represents number 365
  Second List: 8->4->2 //  represents number 248
Output
  Resultant list: 3->1->6  // represents number 613 */

Node* add(Node *first, Node *second) {
	int sum, carry = 0;
	Node *tmp, *res = NULL, *resEnd = NULL;

	while(first or second) {

		sum = (first ? first->data : 0) + (second ? second->data : 0) + carry;
		carry = sum / 10;
		sum %= 10;

		tmp = newNode(sum);

		if(res == NULL) res = resEnd = tmp;

		else resEnd->next = tmp;

		resEnd = tmp;

		if (first) first = first->next;
		if (second) second = second->next;
	}

	if(carry > 0)
		resEnd->next = newNode(carry);

	return res;
}
