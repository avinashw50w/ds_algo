char solve(string s) {
	int n = s.size();
	vector<int> index(256, n);

	for (int i = 0; i < n; ++i) {
		char c = s[i];
		if (index[c] == n) index[c] = i; // c appears for the first time
		else index[c] = n + 1; // c appeared before
	}

	sort(index.begin(), index.end());

	return s[index[0]];
}





/* Given a string, find the first non-repeating character in a single pass of the string.
 * Assume a big character set is in use, like UTF-8, which makes it unfeasible to use a
 * character frequency count table.
 * Avoid any inner loops to have an optimal runtime. Only one pass through the string is allowed.
 *
 * Source: Careercup (Yahoo interview)
 */

struct Node {
	int idx;
	struct Node *prev, *next;
};

void initList(Node* head) {
	head -> prev = head -> next = NULL;
}

void appendList(Node* head, Node* newNode) {
	newNode -> prev = head -> prev;
	newNode -> next = head;
	newNode -> prev -> next = newNode;
	head -> prev = newNode;
}

void deleteList(Node* head, Node* node) {
	node -> prev -> next = node -> next;
	node -> next -> prev = node -> prev;

	node -> prev = node -> next = node;
}

bool emptyList(Node* head) {
	return head -> next == head;
}

bool solve(const string& str) {
	map<char, Node*> M;
	Node head;

	initList(&head);

	for (int i = 0; i < str.size(); ++i) {
		auto it = M.find(str[i]);
		// if a character is found for the third time and so on, then continue
		if (it != M.end() and it -> second == NULL)
			continue;
		// if a character is found for the second time, then remove that character node from the list
		else if (it != M.end())
		{
			deleteList(it -> second);
			delete it -> second;
			it -> second = NULL;
		}
		// if a character is found for the first time, then insert a node for that character in the list
		else
		{
			Node * node = new Node;
			node -> idx = i;
			appendList(&head, node);
			M[str[i]] = node;
		}
	}

	if (emptyList(&head))
		return false;

	return str[head.next -> idx];
}

