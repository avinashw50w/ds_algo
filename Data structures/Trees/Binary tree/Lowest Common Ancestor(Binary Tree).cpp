#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right; 
};

Node* LCA(Node *node, int n1, int n2) {
	if(node == NULL) return NULL;
	if(node->data == n1 || node->data == n2) return node;

	Node* l = LCA(node->left, n1, n2);
	Node* r = LCA(node->right, n1, n2);

	if(l and r) return node;

	return (l ? l : r);
}
//////////////////////////////////////////////////////////////////////

/*Note that the above method assumes that keys are present in Binary Tree. If one key is present 
and other is absent, then it returns the present key as LCA (Ideally should have returned NULL).
We can extend this method to handle all cases by passing two boolean variables v1 and v2. v1 is set 
as true when n1 is present in tree and v2 is set as true if n2 is present in tree.*/
struct Node *findLCAUtil(struct Node* root, int n1, int n2, bool &v1, bool &v2)
{
    if (root == NULL) return NULL;

    if (root->key == n1)
    {
        v1 = true;
        return root;
    }
    if (root->key == n2)
    {
        v2 = true;
        return root;
    }

    Node *left_lca  = findLCAUtil(root->left, n1, n2, v1, v2);
    Node *right_lca = findLCAUtil(root->right, n1, n2, v1, v2);

    if (left_lca && right_lca)  return root;
 
    return (left_lca != NULL)? left_lca: right_lca;
}
 
// Returns true if key k is present in tree rooted with root
bool find(Node *root, int k)
{
    if (root == NULL)
        return false;
 
    if (root->key == k || find(root->left, k) ||  find(root->right, k))
        return true;

    return false;
}
 
// This function returns LCA of n1 and n2 only if both n1 and n2 are present
// in tree, otherwise returns NULL;
Node *findLCA(Node *root, int n1, int n2)
{
    bool v1 = false, v2 = false;
 
    Node *lca = findLCAUtil(root, n1, n2, v1, v2);
 
    // Return LCA only if both n1 and n2 are present in tree
    if (v1 && v2 || v1 && find(lca, n2) || v2 && find(lca, n1))
        return lca;
 
    // Else return NULL
    return NULL;
}
////////////////////////////////////////////////////////////
/*A O(h) time and O(1) Extra Space Solution
:
The above solution requires extra space because we need to use a hash table to store visited ancestors. We can solve the problem in O(1) extra space 
using following fact : If both nodes are at same level and if we traverse up using parent pointers of both nodes, the first common node in the path 
to root is lca.The idea is to find depths of given nodes and move up the deeper node pointer by the difference between depths. Once both nodes reach 
same level, traverse them up and return the first common node.*/
// A Tree Node
struct Node
{
    Node *left, *right, *parent;
    int key;
};
 
// A utility function to create a new BST node
Node *newNode(int item)
{
    Node *temp = new Node;
    temp->key = item;
    temp->parent = temp->left = temp->right = NULL;
    return temp;
}
 
/* A utility function to insert a new node with
given key in Binary Search Tree */
Node *insert(Node *node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);
 
    /* Otherwise, recur down the tree */
    if (key < node->key)
    {
        node->left = insert(node->left, key);
        node->left->parent = node;
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
        node->right->parent = node;
    }
 
    /* return the (unchanged) node pointer */
    return node;
}
// A utility function to find depth of a node
// (distance of it from root)
int depth(Node *node)
{
    int d = -1;
    while (node)
    {
        ++d;
        node = node->parent;
    }
    return d;
}
 
// To find LCA of nodes n1 and n2 in Binary Tree
Node *LCA(Node *n1, Node *n2)
{
    // Find depths of two nodes and differences
    int d1 = depth(n1), d2 = depth(n2);
    int diff = d1 - d2;
 
    // If n2 is deeper, swap n1 and n2
    if (diff < 0)
    {
        Node * temp = n1;
        n1 = n2;
        n2 = temp;
        diff = -diff;
    }
 
    // Move n1 up until it reaches the same level as n2
    while (diff--)
        n1 = n1->parent;
 
    // Now n1 and n2 are at same levels
    while (n1 && n2)
    {
        if (n1 == n2)
            return n1;
        n1 = n1->parent;
        n2 = n2->parent;
    }
 
    return NULL;
}
 
////////////////////////////////////////////////////////////////
// another approach //

bool findPath(Node* node, vector<int>& path, int k) {
	if(node == NULL) return false;
	path.push_back(node->data);
	if(node->data == k) return true;

	if( (node->left and (node->left, path, k))
					or 
		(node->right and findPath(node->right, path, k)) ) 
		return true;

	path.pop_back();
	return false;
}

int LCA(Node* root, int n1, int n2) {
	vector<int> path1, path2;

	if(!findPath(root, path1, n1) || !findPath(root, path2, n2)) return -1;
	int i;
	for(i=0; i<path1.size() and i<path2.size(); ++i)
		if(path1[i] != path2[i]) break;

	return path1[i-1];
}

/////////////////////////////////////////////////////////////////////////////////////
