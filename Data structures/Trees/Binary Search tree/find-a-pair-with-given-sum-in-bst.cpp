/*The idea is same as finding the pair in sorted array (See method 1 of this for details). We traverse BST in Normal Inorder and Reverse Inorder simultaneously. 
In reverse inorder, we start from the rightmost node which is the maximum value node. In normal inorder, we start from the left most node which is minimum value 
node. We add sum of current nodes in both traversals and compare this sum with given target sum. If the sum is same as target sum, we return true. If the sum 
is more than target sum, we move to next node in reverse inorder traversal, otherwise we move to next node in normal inorder traversal. If any of the traversals 
is finished without finding a pair, we return false.*/
struct node {
	int data;
	struct node *left, right;
};

stack<node*> s1, s2;

bool func(node *root, int sum) {

	bool done1, done2, val1, val2;

	node *curr1 = root, *curr2 = root;

	while(1) {
		// get the next inorder val //
		while(!done1) {
			
			if(curr1->left) s1.push(curr1->left), curr1 = curr1->left;

			else {
				
				if(!s1.empty()) {
					curr1 = s1.top(); 
					s1.pop();
					val1 = curr1->data;
					curr1 = curr1->right;
					
				}
				done1 = true;
			}
		}
		// get the next reverse inorder value //
		while(!done2) {
			
			if(curr2->right) s2.push(curr2->right), curr2 = curr2->right;

			else {
				
				if(!s2.empty()) {
					curr2 = s2.top(); 
					s2.pop();
					val2 = curr2->data;
					curr2 = curr2->left;
					
				}
				done2 = true;
			}
		}

		if((val1 != val2) and (val1 + val2) == sum) {
			cout << val1 <<" "<< val2 << endl;

			return true;
		}

		if(val1 + val2 < sum) done1 = false;	

		if(val1 + val2 > sum) done2 = false;

		if(val1 >= val2) return false;
	}
}