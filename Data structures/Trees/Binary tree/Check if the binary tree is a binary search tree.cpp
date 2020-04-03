bool isSubtreeLesser(node* root,int val){
	if(root==NULL) return true;
	if(root->data <= val  && isSubtreeLesser(root->left,val)  &&  isSubtreeLesser(root->right,val))
	return true;
	else return false;
}

bool isSubtreeGreater(node* root,int val){
	if(root==NULL) return true;
	if(root->data > val && isSubtreeGreater(root->left,val) && isSubtreeGreater(root->right,val))
	return true;
	else return false;
}

bool isBST(node* root){
	if(root==NULL) return true;
	if(isSubtreeLesser(root->left,root->data) && isSubtreeGreater(root->right,root->data) && isBST(root->left) && isBST(root->right))
	return true;
	else return false;
}

// else here is a simple approach

bool isBST(node *root,int minval,int maxval){   //  set min= -oo  and max= +oo
	if(root==NULL) return true;
	if(minval < root->data && root->data < maxval && 
		isBST(root->left,minval,root->data) && 
		isBST(root->right,root->data,maxval))
		
		return true;
	
	else return false;
}

/*METHOD 4(Using In-Order Traversal)
Thanks to LJW489 for suggesting this method.
1) Do In-Order Traversal of the given tree and store the result in a temp array.
3) Check if the temp array is sorted in ascending order, if it is, then the tree is BST.

Time Complexity: O(n)

We can avoid the use of Auxiliary Array. While doing In-Order traversal, we can keep track of previously visited node. 
If the value of the currently visited node is less than the previous value, then tree is not BST. Thanks to ygos for this space optimization.*/
bool isBST(struct node* root)
{
    static struct node *prev = NULL;
     
    // traverse the tree in inorder fashion and keep track of prev node
    if (root)
    {
        if (!isBST(root->left))
          return false;
 
        // Allows only distinct valued nodes 
        if (prev != NULL && root->data <= prev->data)
          return false;
 
        prev = root;
 
        return isBST(root->right);
    }
 
    return true;
}
