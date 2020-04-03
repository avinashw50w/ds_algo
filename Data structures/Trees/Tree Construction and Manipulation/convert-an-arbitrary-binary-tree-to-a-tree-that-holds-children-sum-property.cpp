/*Convert an arbitrary Binary Tree to a tree that holds Children Sum Property
Question: Given an arbitrary binary tree, convert it to a binary tree that holds Children Sum Property. You can only 
increment data values in any node (You cannot change structure of tree and cannot decrement value of any node).

For example, the below tree doesn’t hold the children sum property, convert it to a tree that holds the property.

             50
           /     \     
         /         \
       7             2
     / \             /\
   /     \          /   \
  3        5      1      30
Algorithm:
Traverse given tree in post order to convert it, i.e., first change left and right children to hold the children sum property then change the parent node.

Let difference between node’s data and children sum be diff.

     diff = node’s children sum - node’s data  
If diff is 0 then nothing needs to be done.

If diff > 0 ( node’s data is smaller than node’s children sum) increment the node’s data by diff.

If diff < 0 (node’s data is greater than the node's children sum) then increment one child’s data. We can choose to 
increment either left or right child if they both are not NULL. Let us always first increment the left child. 
Incrementing a child changes the subtree’s children sum property so we need to change left subtree also. 
So we recursively increment the left child. If left child is empty then we recursively call increment() for right child.*/
void convert(Node *root) {

	if(root == NULL || (!root->left and !root->right)) return;

	int left_data = 0, right_data = 0, diff;

	convert(root->left);
	convert(root->right);

	if(root->left) left_data = root->left->data;
	if(root->right) right_data = root->right->data;

	diff = left_data + right_data - root->data;

	if(diff > 0) root->data += diff;

	else if(diff < 0) increment(root, -diff);

}

void incrment(Node *root, int diff) {
	if(root->left) {
		root->left->data += diff;
		increment(root->left, diff);
	}
	else if(root->right) {
		root->right->data += diff;
		increment(root->right, diff);
	}
}

/*Time Complexity: O(n^2), Worst case complexity is for a skewed tree such that nodes are in decreasing order from root to leaf.*/
