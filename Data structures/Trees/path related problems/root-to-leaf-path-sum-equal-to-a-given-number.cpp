/*Given a binary tree and a number, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals the given number. 
Return false if no such path can be found.
Algorithm:
Recursively check if left or right child has path sum equal to ( number – value at current node)*/

bool solve(Node *root, int sum) {
	if (!root) return sum == 0;

	sum -= root->data;
	if (isLeaf(root) and sum == 0) return true;

	return solve(root->left, sum) or solve(root->right, sum);
}


///////////////////////////////////////////////////////////////////////////////
// to print the path also , we need to do some changes //

bool hasPathSum(Node* node, vector<int>& path, int sum) {
	if(node == NULL) return false;
	
	if(!node->left and !node->right) {
		if(sum == node->data){
			path.push_back(node->data);
			return true;
		}
		else return false;
	}
	
	if(hasPathSum(node->left, path, sum - node->data)) {
		path.push_back(node->data);
		return true;
	}
	if(hasPathSum(node->right, path, sum - node->data)) {
		path.push_back(node->data);
		return true;
	}
	return false;
}

// path vector contains path from leaf to root, so just reverse it to get path from root to leaf //
