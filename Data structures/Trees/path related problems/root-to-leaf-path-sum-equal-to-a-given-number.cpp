/*Given a binary tree and a number, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals the given number. 
Return false if no such path can be found.
Algorithm:
Recursively check if left or right child has path sum equal to ( number – value at current node)*/

bool hasPathSum(struct node* node, int sum)
{
  	/* return true if we run out of tree and sum==0 */
  	if (node == NULL)
	 	return (sum == 0);
  
	bool ans = 0;  

	/* otherwise check both subtrees */
	int subSum = sum - node->data;

	/* If we reach a leaf node and sum becomes 0 then return true*/
	if ( subSum == 0 && node->left == NULL && node->right == NULL )
	 	return 1;

	if(node->left)
	  	ans = ans || hasPathSum(node->left, subSum);
	if(node->right)
	  	ans = ans || hasPathSum(node->right, subSum);

	return ans;
  
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
