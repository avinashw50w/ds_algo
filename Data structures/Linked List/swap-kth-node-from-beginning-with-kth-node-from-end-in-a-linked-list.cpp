/*Given a singly linked list, swap kth node from beginning with kth node from end. Swapping of data is not allowed, 
only pointers should be changed. This requirement may be logical in many situations where the linked list data part is huge 
(For example student details line Name, RollNo, Address, ..etc). 
The pointers are always fixed (4 bytes for most of the compilers).

Let X be the kth node from beginning and Y be the kth node from end. Following are the interesting cases that must be handled.
1) Y is next to X
2) X is next to Y
3) X and Y are same
4) X and Y don’t exist (k is more than number of nodes in linked list)*/

void swapKthNode(Node **root, int k) {
	int n = countNodes(root);

	if (k > n) return;
	// if both x and y are at same position
	if(2*k - 1 == n) return;

	Node *x = *root, prev_x = NULL;
	for(int i = 1; i < k; ++i) {
		prev_x = x;
		x = x->next;
	}

	Node *y = *root, prev_y = NULL;
	for(int i = 1; i < n-k+1; ++i) {
		prev_y = y;
		y = y->next;
	}

	if(prev_x) prev_x->next = y;

	if(prev_y) prev_y->next = x;

	Node *tmp = x->next;
	x->next = y->next;
	y->next = tmp;

	if(k == 1) *head = y;
	else if(k == n) *head = x;
}
