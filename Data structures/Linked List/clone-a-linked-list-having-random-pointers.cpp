/*You are given a Double Link List with one pointer of each node pointing to the next node just like in a single link list. The second pointer however CAN point 
to any node in the list and not just the previous node. Now write a program in O(n) time to duplicate this list. That is, write a program which will create a 
copy of this list.*/

struct node {
	int data;
	struct node *next, *random;
}

node *head = NULL;

node* newNode(int data) {
	node *tmp = new node();
	tmp->data = data;
	tmp->next = tmp->random = NULL;
	return tmp;
}

node* push(node* head, int data) {
	node* tmp = new node();

	tmp->data = data;
	tmp->next = head;
	head = tmp;
	return tmp;
}

node* clone(node *head) {
	node *origCurr = head, cloneCurr = NULL;

	map<node*, node*> m;

	while(origCurr != NULL) {
		cloneCurr = newNode(origCurr->data);
		m[origCurr] = cloneCurr;
		origCurr = origCurr->next;
	}

	origCurr = head;

	while(origCurr != NULL) {
		cloneCurr = m[origCurr];
		cloneCurr->next = m[origCurr->next];
		cloneCurr->random = m[origCurr->random];
		origCurr = origCurr->next;
	}

	return 
}