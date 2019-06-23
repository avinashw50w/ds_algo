node* newNode(int val){
	node* temp= new node();
	temp->data = val;
	temp->left = temp->right = NULL;
	return temp;
}

int search(int A[],int l,int r,int x){
	while(l<=r){
		int mid = (l+r)/2;
		if(x==A[mid]) return mid;
		else if(x<A[mid]) r=mid-1;
		else l=mid+1;
	}
	return -1;
}

node* buildTree(int in[],int pre[],int instart,int inend){
	if(instart>inend) return NULL;
	static int preIndex=0;
	node* Node = newNode(pre[preIndex++]);
	
	if(instart==inend) return Node;
	
	int inIndex = search(in,instart,inend,Node->data);
	Node->left = buildTree(in,pre,instart,inIndex-1);
	Node->right = buildTree(in,pre,inIndex+1,inend);
	
	return Node;
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
