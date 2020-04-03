/*There are numerous applications we need to find floor (ceil) value of a key in a binary search tree or sorted array. For example, consider 
designing memory management system in which free nodes are arranged in BST. Find best fit for the input request.

Ceil Value Node: Node with smallest data larger than or equal to key value.*/

// Function to find ceil of a given input in BST. If input is more
// than the max key in BST, return -1
int Ceil(node *root, int key)
{
    // Base case
    if( root == NULL )
        return -1;
 
 	int ceiling;
    // We found equal key
    if( root->key == key)
        ceiling = root->key;
 
    // If root's key is smaller, ceil must be in right subtree
    else if( root->key < input )
        ceiling = Ceil(root->right, input);
 
    // Else, either left subtree or root has the ceil value
    else {
		ceiling = Ceil(root->left, input);
		if(ceiling == -1) ceiling = root->data;
	}
	
	return ceiling;
}

int Floor(node *root, int key) {
	if(root == NULL) return -1;
	
	int floor;
	if(root->data == key)
		floor = root->data;
	
	else if(root->data < key) {
		floor = Floor(root->right, key);
		if(floor == -1) floor = root->data;
	}
	
	else 
		floor = Floor(root->left, key);
	
	return floor;
}


