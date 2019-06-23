
void reverseLevelOrder(Node *root) {

	int h = height(root);

	for(int i = h; i >= 1; --i) {
		printLevel(root, i);
	}
}

void printLevel(Node *root, int level) {
	if(root == NULL) return;

	if(level == 1) cout << root->data <<" ";

	else if(level > 1) {
		printLevel(root->left, level-1);
		printLevel(root->right, level-1);
	}
}
/*Time Complexity: The worst case time complexity of this method is O(n^2). For a skewed tree, printGivenLevel() 
takes O(n) time where n is the number of nodes in the skewed tree. So time complexity of printLevelOrder() is 
O(n) + O(n-1) + O(n-2) + .. + O(1) which is O(n^2).*/

///////////////////////////////////////////////////////////////////////////////////////
/*METHOD 2 (Using Queue and Stack)
The method 2 of normal level order traversal can also be easily modified to print level order traversal in reverse order. 
The idea is to use a stack to get the reverse level order. If we do normal level order traversal and instead of printing 
a node, push the node to a stack and then print contents of stack, we get “5 4 3 2 1″ for above example tree, but output 
should be “4 5 2 3 1″. So to get the correct sequence (left to right at every level), we process children of a node in 
reverse order, we first push the right subtree to stack, then left subtree.*/

void reverseLevelOrder(node* root)
{
    stack <node *> S;
    queue <node *> Q;
    Q.push(root);
 
    // Do something like normal level order traversal order. Following are the
    // differences with normal level order traversal
    // 1) Instead of printing a node, we push the node to stack
    // 2) Right subtree is visited before left subtree
    while (Q.empty() == false)
    {
        /* Dequeue node and make it root */
        root = Q.front();
        Q.pop();
        S.push(root);
 
        /* Enqueue right child */
        if (root->right)
            Q.push(root->right); // NOTE: RIGHT CHILD IS ENQUEUED BEFORE LEFT
 
        /* Enqueue left child */
        if (root->left)
            Q.push(root->left);
    }
 
    // Now pop all items from stack one by one and print them
    while (S.empty() == false)
    {
        root = S.top();
        cout << root->data << " ";
        S.pop();
    }
}
 