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

class Trie {
	static const int ROOT = 0;
	int sz;
	vector<unordered_map<int, int>> t;
	vector<int> leaf;

	Trie(int N) {
		t.resize(N);
		leaf.resize(N);
		sz = 1;
	}

	void insert(string s) {
		int node = ROOT;
		for (int i = 0; i < s.size(); ++i) {
			char c = s[i] - 'a';
			if (t[node].count(c) == 0)
				t[node][c] = sz++;
			node = t[node][c];
		}
		leaf[node]++;
	}

	bool query(string s) {
		int node = ROOT;
		for (int i = 0; i < s.size(); ++i) {
			char c = s[i] - 'a';
			if (t[node].count(c) == 0) return false;
			node = t[node][c];
		}
		return leaf[node];
	}

	string lcp() {
		int node = ROOT;
		string ans = "";
		while (t[node].size() == 1) {
			auto p = *t[node].begin();
			ans += p.first + 'a';
			node = p.second;
		}
		return ans;
	}
};

////////////////////////////////////////////////////////////////
struct Node {
	bool leaf;
	Node *ch[26];
};

Node *newNode() {
	Node *tmp = new Node();

	tmp->leaf = false;
	for (int i = 0; i < 26; ++i) ch[i] = NULL;
	return tmp;
}

void insert(Node *root, string s) {

	Node *curr = root;

	for (int i = 0; i < s.size(); ++i) {
		int idx = s[i] - 'a';

		if (curr->ch[idx] == NULL)
			curr->ch[idx] = newNode();

		curr = curr->ch[idx];
	}
	curr->leaf = true;
}
/*--------------------------------------------------------*/
void countNodes(Node *root, int &idx) {

	int cnt = 0;
	Node *curr = root;
	for (int i = 0; i < 26; ++i) {
		if (curr->ch[i] != NULL) {
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

	while (countNodes(curr, idx) == 1 and curr->leaf = false) {
		curr = curr->ch[idx];

		res += (idx + 'a');
	}

	return res;
}


string commonPrefix(string a[], int n) {

	Node *root = newNode();

	for (int i = 0; i < n; ++i)
		insert(root, a[i]);

	return commonPrefixUtil(root);
}

/*----------------------------------------------------------------------*/

