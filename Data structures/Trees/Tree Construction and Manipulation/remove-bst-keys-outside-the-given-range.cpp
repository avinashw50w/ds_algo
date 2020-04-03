/*Given a Binary Search Tree (BST) and a range [min, max], remove all keys which are outside the given range. 
The modified tree should also be BST. For example, consider the following BST and range [-10, 13]. 

						6
					   /  \
					 -13  14
					  \   /  \
					 -8  13   15
					     /
					    7
The given tree should be changed to following. Note that all keys outside the range [-10, 13] are removed and modified tree is BST.

						6
					   /  \
					 -8   13
					     /
					    7

There are two possible cases for every node.
1) Node’s key is outside the given range. This case has two sub-cases.
…….a) Node’s key is smaller than the min value.
…….b) Node’s key is greater that the max value.
2) Node’s key is in range.

We don’t need to do anything for case 2. In case 1, we need to remove the node and change root of sub-tree rooted with this node.
The idea is to fix the tree in Postorder fashion. When we visit a node, we make sure that its left and right sub-trees are already fixed. 
In case 1.a), we simply remove root and return right sub-tree as new root. In case 1.b), we remove root and return left sub-tree as new root.*/

// Resmoves all nodes having value outside the given range and returns the root
// of modified tree
node* removeOutsideRange(node *root, int min, int max)
{
   // Base Case
   if (root == NULL)
      return NULL;
 
   // First fix the left and right subtrees of root
   root->left =  removeOutsideRange(root->left, min, max);
   root->right =  removeOutsideRange(root->right, min, max);
 
   // Now fix the root.  There are 2 possible cases for toot
   // 1.a) Root's key is smaller than min value (root is not in range)
   // so, replace root with a next greater value, which is present in the root's right child
   if (root->key < min)
   {
       node *rChild = root->right;
       delete root;
       return rChild;
   }
   // 1.b) Root's key is greater than max value (root is not in range)
   //so, replace root with a next smaller value, which is present in the root's left child
   if (root->key > max)
   {
       node *lChild = root->left;
       delete root;
       return lChild;
   }
   // 2. Root is in range
   return root;
}