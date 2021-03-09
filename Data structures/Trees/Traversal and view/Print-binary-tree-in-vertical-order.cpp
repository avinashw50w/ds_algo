/*Given a binary tree, print it vertically. The following example illustrates vertical order traversal.

           1
        /    \
       2      3
      / \    / \
     4   5  6   7
             \   \
              8   9


The output of print this tree vertically will be:
4
2
1 5 6
3 8
7
9   */
/*Time Complexity: Time complexity of above algorithm is O(w*n) where w is width of Binary Tree and n is
number of nodes in Binary Tree. In worst case, the value of w can be O(n) (consider a complete tree for example)
and time complexity can become O(n2).*/

// Time complexity : O(n)

void solve(Node *root, map<int, vector<int>> M, int hd) {
	if (!root) return;

	M[hd].push_back(root->data);

	solve(root->left, M, hd - 1);
	solve(root->right, M, hd + 1);
}

void verticalOrder(Node *root) {

	map<int, vector<int>> M;
	int hd = 0;

	solve(root, M, hd);

	for (auto i : M) {
		printf("%d : ", i.first);
		for (int k : i.second)
			printf("%d ", k);
		printf("\n");
	}
}
////////////////////////////////////////
void findMinMax(Node *root, int &mini, int &maxx, int hd) {
	if (!root) return;

	if (hd < mini) mini = hd;
	else if (hd > maxx) maxx = hd;

	findMinMax(root->left, mini, maxx, hd - 1);
	findMinMax(root->right, mini, maxx, hd + 1);
}

void printVerticalLine(Node *root, int line, int hd) {
	if (!root) return;

	if (hd == line) cout << root->data << " ";

	printVerticalLine(root->left, line, hd - 1);
	printVerticalLine(root->right, line, hd + 1);
}


void VerticalOrder(Node *root) {
	int mini = 0, maxx = 0;

	findMinMax(root, mini, maxx, 0);

	for (int line = mini; line <= maxx; ++line) {
		printVerticalLine(root, line, 0);
		cout << endl;
	}
}
//////////////////////////////////////////////////////////////////////

