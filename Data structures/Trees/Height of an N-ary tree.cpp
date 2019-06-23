
struct Node {

	int data;
	vector<Node*> children;
};

int height(Node *root) {

	if (!root) return 0;
	int mx = 0;

	for (int i = 0; i < N; ++i) {
		mx = max(mx, height(root->children[i]));
	}

	return 1 + mx;
}

//////////////////////////////////////////////////
/// if parent array is given


int height(int par[], int N) {
	int res = 0;

	// traverse each node from bottom to top
	for (int i = 0; i < N; ++i) {
		int cnt = 1, p = par[i];

		while(p != -1) {
			cnt++;
			p = par[p];
		}

		res = max(res, cnt);
	}

	return res;
}