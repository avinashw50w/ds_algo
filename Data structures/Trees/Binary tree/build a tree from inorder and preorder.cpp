Node* newNode(int val){
	Node* temp= new Node();
	temp->data = val;
	temp->left = temp->right = NULL;
	return temp;
}

Node *buildTree(vector<int> inorder, vector<int> preorder) {
    int n = inorder.size();
    unordered_map<int,int> mp;
    for (int i = 0; i < n; ++i) mp[in[i]] = i;

    buildTreeUtil(0, n-1, preorder, 0, mp);
}

Node* buildTree(int start, int end, vector<int> &preorder, int &preIndex,  auto &mp){
	if(start > end) return NULL;
	Node* node = newNode(preorder[preIndex++]);
	
	if(start == end) return node;
	
	int inIndex = mp[node->data];
	
    node->left = buildTree(start, inIndex - 1, preorder, preIndex, mp);
	node->right = buildTree(inIndex + 1, end, preorder, preIndex, mp);
	
	return node;
}

/*Let us consider the below traversals:

Inorder sequence: D B E A F C
Preorder sequence: A B D E C F

In a Preorder sequence, leftmost element is the root of the tree. So we know ‘A’ is root for given sequences. By searching ‘A’ in Inorder sequence, 
we can find out all elements on left side of ‘A’ are in left subtree and elements on right are in right subtree. So we know below structure now.

                 A
               /   \
             /       \
           D B E     F C
We recursively follow above steps and get the following tree.

         A
       /   \
     /       \
    B         C
   / \        /
 /     \    /
D       E  F
Algorithm: buildTree()
1) Pick an element from Preorder. Increment a Preorder Index Variable (preIndex in below code) to pick next element in next recursive call.
2) Create a new tree node tNode with the data as picked element.
3) Find the picked element’s index in Inorder. Let the index be inIndex.
4) Call buildTree for elements before inIndex and make the built tree as left subtree of tNode.
5) Call buildTree for elements after inIndex and make the built tree as right subtree of tNode.
6) return tNode.
*/
