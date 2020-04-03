// iterative inorder

#include <unordered_map>
unordered_map<Node*, int> cnt;

void inorder(Node* root) {

	stack<Node*> S;

	S.push(root);

	while (!S.empty()) {

		Node* curr = S.top();
		if (curr == NULL) { S.pop(); continue; }
		if (cnt[curr] == 0) S.push(curr->left);
		else if (cnt[curr] == 1) cout << curr->data << " ";
		else if (cnt[curr] == 2) S.push(curr->right);
		else S.pop();
		cnt[curr]++;
	}
}

// iterative preorder

void preorder(Node* root) {

	stack<Node*> S;

	S.push(root);

	while (!S.empty()) {

		Node* curr = S.top();
		if (curr == NULL) { S.pop(); continue; }
		if (cnt[curr] == 0) cout << curr->data << " ";
		else if (cnt[curr] == 1) S.push(curr->left);
		else if (cnt[curr] == 2) S.push(curr->right);
		else S.pop();
		cnt[curr]++;
	}
}