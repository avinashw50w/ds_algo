/*XOR linked list is a memory efficient doubly linked list
each node stores an extra value npx which is the xor of address of prev and the next node
to traverse to the next node, we xor the prev node address with the npx of the current node
*/

struct Node {
	int data;
	Node *npx;
};

Node* XOR(Node *a, Node *b) {
	return (Node*) ((uintptr_t)a ^ (uintptr_t)b);
}

void insert(Node *&head, int data) {
	Node *node = new Node();
	node->data = data;

	node->npx = head;

	if (head) {
		head->npx = XOR(head->npx, node);
	}

	head = node;
}

void print(Node *head) {
	Node *prev = NULL, *curr = head;
	while (curr) {
		cout << curr->data << " ";
		Node *next = XOR(prev, curr->npx);

		prev = curr;
		curr = next;
	}
}