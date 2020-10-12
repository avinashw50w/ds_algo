/*Given a Binary Tree, find vertical sum of the nodes that are in same vertical line. Print all sums through different vertical lines.

Examples:

      1
    /   \
  2      3
 / \    / \
4   5  6   7
The tree has 5 vertical lines

Vertical-Line-1 has only one node 4 => vertical sum is 4
Vertical-Line-2: has only one node 2=> vertical sum is 2
Vertical-Line-3: has three nodes: 1,5,6 => vertical sum is 1+5+6 = 12
Vertical-Line-4: has only one node 3 => vertical sum is 3
Vertical-Line-5: has only one node 7 => vertical sum is 7

So expected output is 4, 2, 12, 3 and 7

Solution:
We need to check the Horizontal Distances from root for all nodes. If two nodes have the same Horizontal Distance (HD),
then they are on same vertical line. The idea of HD is simple. HD for root is 0, a right edge (edge connecting to right subtree)
is considered as +1 horizontal distance and a left edge is considered as -1 horizontal distance. For example, in the above tree,
HD for Node 4 is at -2, HD for Node 2 is -1, HD for 5 and 6 is 0 and HD for node 7 is +2.
We can do inorder or preorder traversal of the given Binary Tree. While traversing the tree, we can recursively calculate HDs. We initially
pass the horizontal distance as 0 for root. For left subtree, we pass the Horizontal Distance as Horizontal distance of root minus 1.
For right subtree, we pass the Horizontal Distance as Horizontal Distance of root plus 1.*/

struct Node {
  int data; //data of the node
  Node *left, *right; //left and right references
  // Constructor of tree node
  Node(int key) {
    data = key;
    left = right = NULL;
  }
};
/*------------------------------------------*/
map<int, int> m;
void vsum(struct Node *root, int c)
{
  if (!root)
    return;

  m[c] += root->data;
  vsum(root->left, c - 1);
  vsum(root->right, c + 1);
}
/*----------------------------------------------*/
int main()
{
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);
  cout << "Vertical Sum of the given binary tree :\n";
  vsum(root, 0);

  for (map<int, int> ::iterator it = m.begin(); it != m.end(); ++it)
    cout << it->first << " = " << it->second << endl;
  return 0;
}
///////////////////////////////////////////////////////////////////////////////
// space optimized //
/*We have discussed Hashing Based Solution in Set 1. Hashing based solution requires a Hash Table to be maintained.
We know that hashing requires more space than the number of entries in it. In this post, Doubly Linked List based solution is discussed.
The solution discussed here requires only n nodes of linked list where n is total number of vertical lines in binary tree. Below is algorithm.

verticalSumDLL(root)
1)  Create a node of doubly linked list node
    with value 0. Let the node be llnode.
2)  verticalSumDLL(root, llnode)

verticalSumDLL(tnode, llnode)
1) Add current node's data to its vertical line
        llnode.data = llnode.data + tnode.data;
2) Recursively process left subtree
   // If left child is not empty
   if (tnode.left != null)
   {
      if (llnode.prev == null)
      {
          llnode.prev = new LLNode(0);
          llnode.prev.next = llnode;
      }
      verticalSumDLLUtil(tnode.left, llnode.prev);
   }
3)  Recursively process right subtree
   if (tnode.right != null)
   {
      if (llnode.next == null)
      {
          llnode.next = new LLNode(0);
          llnode.next.prev = llnode;
      }
      verticalSumDLLUtil(tnode.right, llnode.next);
   }*/

/* node of a doubly linked list */
struct DLLNode
{
  int data;
  DLLNode *next, *prev;
};

/* node of a binary tree */
struct BTNode
{
  int data;
  BTNode *left, *right;
};

BTNode* newBTNode(int data)
{
  BTNode* node = (BTNode*)malloc(sizeof(BTNode));
  node->data = data;
  node->left = node->right = NULL;

  return node;
}

DLLNode* newDLLNode(int data)
{
  DLLNode* node = (DLLNode*)malloc(sizeof(DLLNode));
  node->data = data;
  node->next = node->prev = NULL;

  return node;
}

void verticalOrderUtil(BTNode* root, DLLNode*& node)
{
  // Add current node's data to its vertical line
  node->data = node->data + root->data;

  // Recursively process left subtree
  if (root->left)
  {
    if (node->prev == NULL)
    {
      node->prev = newDLLNode(0);
      node->prev->next = node;
    }
    verticalOrderUtil(root->left, node->prev);
  }

  // Process right subtree
  if (root->right)
  {
    if (node->next == NULL)
    {
      node->next = newDLLNode(0);
      node->next->prev = node;
    }
    verticalOrderUtil(root->right, node->next);
  }
}

void verticalOrder(BTNode* root)
{
  DLLNode* head = newDLLNode(0);
  verticalOrderUtil(root, head);

  while (head->prev) {
    head = head->prev;
  }
  // Prints vertical sum of all lines starting from leftmost vertical line
  while (head) {
    cout << head->data << " ";
    head = head->next;
  }
}
int main()
{
  BTNode* root = newBTNode(1);
  root->left = newBTNode(2);
  root->right = newBTNode(3);
  root->left->left = newBTNode(4);
  root->left->right = newBTNode(5);
  root->right->left = newBTNode(6);
  root->right->right = newBTNode(7);

  verticalOrder(root);

  return 0;
}