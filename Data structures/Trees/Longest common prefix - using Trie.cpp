/*Given a set of strings, find the longest common prefix.

Input  : {“geeksforgeeks”, “geeks”, “geek”, “geezer”}
Output : "gee"

Input  : {"apple", "ape", "april"}
Output : "ap"
Steps:

Insert all the words one by one in the trie. After inserting we perform a walk on the trie.
In this walk, go deeper until we find a node having more than 1 children(branching occurs) or 0 children (one of the string gets exhausted).
This is because the characters (nodes in trie) which are present in the longest common prefix must be the single child of its parent, 
i.e- there should not be a branching in any of these nodes.*/
struct Node {
	bool leaf;
	Node *ch[26];
};

Node *newNode() {
	Node *tmp = new Node();

	tmp->leaf = false;
	for(int i = 0; i < 26; ++i) ch[i] = NULL;
	return tmp;
}

void insert(Node *root, string s) {

	Node *curr = root;

	for(int i = 0; i < s.size(); ++i) {
		int idx = s[i]-'a';

		if(curr->ch[idx] == NULL) 
			curr->ch[idx] = newNode();
		
		curr = curr->ch[idx];
	}
	curr->leaf = true;
}
/*--------------------------------------------------------*/
void countNodes(Node *root, int &idx) {

	int cnt = 0;
	Node *curr = root;
	for(int i = 0; i < 26; ++i) {
		if(curr->ch[i] != NULL) {
			cnt++;
			idx = i;
		}
	}
	return cnt;
}

string commonPrefixUtil(Node *root) {

	string res = "";
	int idx = 0;

	Node* curr = root;

	while(countNodes(curr, idx) == 1 and curr->leaf = false) {
		curr = curr->ch[idx];

		res += (idx + 'a');
	}

	return res;
}


string commonPrefix(string a[], int n) {

	Node *root = newNode();

	for(int i = 0; i < n; ++i)
		insert(root, a[i]);

	return commonPrefixUtil(root);
}

/*----------------------------------------------------------------------*/

