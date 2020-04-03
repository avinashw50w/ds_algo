

void getDiagonals(Node *root, int d, map<int, vector<int> > &m) {
	if(root == NULL) return;

	m[d].push_back(root->data);

	getDiagonals(root->left, d+1, m);
	getDiagonals(root->right, d, m);
} 


void diagonalTraversal(Node *root) {

	map<int, vector<int> > m;

	getDiagonals(root, 0, m);

	for(auto v: m) {
		for(auto i: v.second) {
			cout << i << " ";
		}
		cout << endl;
	}
}