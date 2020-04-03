/*eg. if preorder traversal is given { 5,2,1,3,4,7,6,8 }. Then construct the bst from it. */
/* the tree is contructed by breaking the list into left and right subtree : 

			5
		 /     \
	 2,1,3,4   7,6,8
{nodes less  {nodes greater 
than 5}			than 5 }
*/

int findDivision(int preoder[], int l, int h, int val) {
	for (int i = l; i <= h; ++i) {
		if (val < preorder[i]) break;
	}
	return i;
}

Node* deserialize(int preorder[], int l, int h) {
	if (l > h) return NULL;

	Node *root = newNode(preorder[l]);

	int divIndex = findDivision(preorder, l+1, h, root->val);

	root->left = deserialize(preorder, l+1, divIndex-1);

	root->right = deserialize(preorder, divIndex, h);

	return root;
}

/////////////////////////////////////////////////////////////
/* O(n) solution */

Node *deserialize(vector<int> preorder, int currIdx, int mini, int maxx) {
	if (currIdx > preorder.size()) return NULL;

	Node *root = NULL;

	if (mini < preorder[currIdx] and preorder[currIdx] < maxx) {
		root = newNode(preorder[currIdx]);

		currIdx++;

		root->left = deserialize(preorder, currIdx, mini, root->data);

		root->right = deserialize(preorder, currIdx, root->data, maxx);
	}

	return root;
}


int main() {

	deserialize(preorder, 0, INT_MIN, INT_MAX);
}