/*given the root of a tree and a target node, find the nodes which are at a distance of K
from the target.

the problem can be solved by two methods:
method 1: create a new graph to represent the tree (either adjacency matrix or adj list),
	then run dfs from the target to get nodes at a distance of K
method 2:
	- find all the nodes at a distance of K which lies in the subtree rooted at target.
	- find all the nodes at a distance of K which lies outside of subtree rooted at target.*/

// get all the nodes in the subtree rooted at node
void getNodesInSubtree(Node *node, int K, vector<int> &res) {
	if (!node) return;
	if (K == 0) {
		res.push_back(node->data);
		return;
	}
	getNodesInSubtree(node->left, K - 1, res);
	getNodesInSubtree(node->right, K - 1, res);
}

int solve(Node *node, Node *target, int K, vector<int> &res) {
	if (!node) return -1;
	if (node == target) {
		getNodesInSubtree(node, K, res);
		return 0;
	}

	// dl =  distance of target from node->left if target exists in left subtree of the node, otherwise -1
	int dl = solve(node->left, K, res);
	if (dl != -1) {
		if (dl + 1 == K) res.push_back(node);
		else getNodesInSubtree(node->right, K - dl - 2);
		return dl + 1;
	}

	int dr = solve(node->right, K, res);
	if (dr != -1) {
		if (dr + 1 == K) res.push_back(node);
		else getNodesInSubtree(node->right, K - dr - 2);
		return dr + 1;
	}

	return -1; // if target is not found
}

// main function
vector<int> getNodesAtDistanceK(Node *root, Node *target, int K) {
	vector<int> res;
	solve(root, target, K, res);
	return res;
}

