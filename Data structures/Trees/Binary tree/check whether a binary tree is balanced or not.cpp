struct Node 
{
	int data;
	Node *left, *right;
};

//main function
bool isBalanced(Node *n)
{
	if(balancedHeight(n) > -1) return true;

	return false;
}

int balancedHeight(Node *n)
{
	if(n == NULL) return 0;

	int h1 = balancedHeight(n -> left);
	int h2 = balancedHeight(n -> right);

	if(h1 == -1 or h2 == -1) return -1;

	if(abs(h1-h2) > 1) return -1;

	return 1 + max(h1, h2);
}