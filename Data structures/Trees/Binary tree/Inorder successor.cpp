// inorder successor
node* Find(node* root,int data){
	if(root == NULL) return root;
	if(root->data == data) return root;
	if(data < root->data) Find(root->left);
	else Find(root->right);
}

node* findMin(node* root){
	while(root->left)
		root = root->left;
	return root;
}

node* getSuccessor(node* root,int data){
	node* curr = Find(root,data);
	if(curr==NULL) return NULL;
	if(curr->right!=NULL)             //  if right child is not NULL
		return findMin(curr->right);
	else{                           //  if right child is NULL  then find its nearest ancestor for which this node lies in its left or right subtree depending on its value.
		node* successor = NULL;
		node* ancestor = root;
		while(ansector!=curr){
			if(curr->data < ancestor->data){
				successor = ancestor;
				ancestor = ancestor->left;
			}
			else ancestor = ancestor->right;
		}
		return successor;
	}
}

//another method is using a pointer to its parent

struct node{
	int data;
	node* left,*right,*parent;
};
struct node * inOrderSuccessor(struct node *root, struct node *n)
{
  // if right child exists
  if( n->right != NULL )
    return minValue(n->right);
 
  // if right child doesn't exist 
  struct node *p = n->parent;
  while(p != NULL && n == p->right)
  {
     n = p;
     p = p->parent;
  }
  return p;
}

