/*Flatten a multilevel linked list
Given a linked list where in addition to the next pointer, each node has a child pointer, which may or may not point to a separate list. 
These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, as shown in below figure.
You are given the head of the first level of the list. Flatten the list so that all the nodes appear in a single-level linked list. 
You need to flatten the list in way that all nodes at first level should come first, then nodes of second level, and so on.

	10 --> 5 --> 12 --> 7 --> 11
	|	   				|
	4 --> 20 --> 13     17--> 6
		  |      |      |
		  2 	 16     9 --> 8
		  		 |		|
		  		 3      19-->15

The above list should be converted to 10->5->12->7->11->4->20->13->17->6->2->16->9->8->3->19->15

The problem clearly say that we need to flatten level by level. The idea of solution is, we start from first level, 
process all nodes one by one, if a node has a child, then we append the child at the end of list, otherwise we don’t do anything. 
After the first level is processed, all next level nodes will be appended after first level. Same process is followed for the appended nodes.

1) Take "cur" pointer, which will point to head of the fist level of the list
2) Take "tail" pointer, which will point to end of the first level of the list
3) Repeat the below procedure while "curr" is not NULL.
    I) if current node has a child then
	a) append this new child list to the "tail"
		tail->next = cur->child
	b) find the last node of new child list and update "tail"
		tmp = cur->child;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tail = tmp;
    II) move to the next node. i.e. cur = cur->next */


struct Node{
	int data;
	struct Node *next, *child;
};

void flatten(Node *head) {

	Node *curr = head, *tail = head;

	while(tail->next) tail = tail->next;

	while(curr != NULL) {

		if(curr->child) {
			tail->next = curr->child;

			Node *tmp = curr->child;
			while(tmp->next) tmp = tmp->next;

			tail = tmp;
		}

		curr = curr->next;
	}
}