

bool sameTree(node* a,node* b){
	if(a==NULL && b==NULL) return true;
	if(a!=NULL && b!=NULL){
		return (a->data==b->data &&
			sameTree(a->left,b->left) &&
			sameTree(a->right,b->right)
			);
		}
	return 0;
}

//////////////////////////////////////////////////////////////////////////
// iterative //
/*The idea is to use level order traversal. We traverse both trees simultaneously 
and compare the data whenever we dequeue and item from queue.*/

// Iterative method to find height of Bianry Tree
bool areIdentical(Node *root1, Node *root2)
{
    // Return true if both trees are empty
    if (!root1  && !root2) return true;
 
    // Return false if one is empty and other is not
    if (!root1 || !root2)  return false;
 
    // Create an empty queues for simultaneous traversals 
    queue<Node *> q1, q2;
 
    // Enqueue Roots of trees in respective queues
    q1.push(root1);
    q2.push(root2);
 
    while (!q1.empty() && !q2.empty())
    {
        // Get front nodes and compare them
        Node *n1 = q1.front();
        Node *n2 = q2.front();
 
        if (n1->data != n2->data)
           return false;
 
        // Remove front nodes from queues
        q1.pop(), q2.pop();
 
        /* Enqueue left children of both nodes */
        if (n1->left && n2->left)
        {
            q1.push(n1->left);
            q2.push(n2->left);
        }
 
        // If one left child is empty and other is not
        else if (n1->left || n2->left)
            return false;
 
        // Right child code (Similar to left child code)
        if (n1->right && n2->right)
        {
            q1.push(n1->right);
            q2.push(n2->right);
        }
        else if (n1->right || n2->right)
            return false;
    }
 
    return true;
}
