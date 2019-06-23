/*Print extreme nodes of each level of Binary Tree in alternate order
– print rightmost node of 1st level
– print leftmost node of 2nd level
– print rightmost node of 3rd level
– print leftmost node of 4th level
– print rightmost node of 5th level

OR

1 3 4 15 16
– print leftmost node of 1st level
– print rightmost node of 2nd level
– print leftmost node of 3rd level
– print rightmost node of 4th level
– print leftmost node of 5th level*/

/*The idea is to traverse tree level by level. For each level, we count number of nodes in it and print its leftmost 
or the rightmost node based on value of a Boolean flag. We dequeue all nodes of current level and enqueue all nodes of 
next level and invert value of Boolean flag when switching levels.*/

/* Function to print nodes of extreme corners
of each level in alternate order */
void printExtremeNodes(Node* root)
{
    if (root == NULL)
        return;
 
    queue<Node*> q;
    q.push(root);
 
    // flag to indicate whether leftmost node or
    // the rightmost node has to be printed
    bool flag = false;
    while (!q.empty())
    {
        // nodeCount indicates number of nodes
        // at current level.
        int nodeCount = q.size();
        int n = nodeCount;
 
        // Dequeue all nodes of current level
        // and Enqueue all nodes of next level
        while (n--)
        {
            Node* curr = q.front();
 
            if (curr->left)
                q.push(curr->left);
 
            if (curr->right)
                q.push(curr->right);

            q.pop();
 
            // if flag is true, print leftmost node
            if (flag && n == nodeCount - 1)
                cout << curr->data << " ";
 
            // if flag is false, print rightmost node
            if (!flag && n == 0)
                cout << curr->data << " ";
        }
        // invert flag for next level
        flag = !flag;
    }
}
 