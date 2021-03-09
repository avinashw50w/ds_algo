
struct Node {
	char ch;
	int freq;
	Node *left, *right;
	Node(char ch, int freq) {
		this->ch = ch;
		this->freq = freq;
		left = right = NULL;
	}
};

void encode(Node *root, string s, auto &mp) {
	if (!root) return;
	if (!root->left and !root->right) {
		mp[root->ch] = s == "" ? 1 : s;
		return;
	}

	encode(root->left, s + "0", mp);
	encode(root->right, s + "1", mp);
}

void decode(Node *root, int &pos, string code) {
	if (!root) return;
	if (isLeaf(root)) {
		cout << root->ch;
		return;
	}

	pos++;
	if (code[pos] == "0") decode(root->left, pos, code);
	else decode(root->right, pos, code);
}

auto cmp = [](Node *&a, Node *&b) { return a.freq > b.freq; };

void buildHuffmanTree(text) {
	if (text.length() == 0) return;
	unordered_map<char, int> f;
	for (char c : text) f[c]++;
	// min heap
	priority_queue < Node*, vector<Node*>, decltype(cmp)> q(cmp);

	for (auto p : f) {
		q.push(Node(p.first, p.second));
	}

	while (q.size() != 1) {
		Node *left = q.top(); q.pop();
		Node *right = q.top(); q.pop();

		int sum = left->freq + right->freq;
		q.push(Node('#', sum));
	}

	Node *root = q.top(); q.pop();

	unordered_map<char, string> huffmanCode;
	encode(root, "", huffmanCode);
}

int main() {
	string text = "Hello world";
	buildHuffmanTree(text);
}