#include<iostream>
#include<queue>
using namespace std;
struct node{
	int data;
	node* left,*right;
};
node* root=NULL;
node* newNode(int n){
	node* temp = new node();
	temp->data = n;
	temp->left = temp->right = NULL;
	return temp;
}
// pass node **root if root is declared in main.
node* insert(node* root,int n){           //  O(logn)
	if(root==NULL)
		return newNode(n);
	
	if(n < root->data)
		root->left = insert(root->left,n);
	else if(n > root->data)
		root->right = insert(root->right,n);
	return root;
}

void preorder(node* root){          //  O(n)
	if(root==NULL) return;
	cout<<root->data<<endl;   //  V L R  traversal  . for inorder : L V R  , for postorder : L R V    .. these are basically depth first traversals
	preorder(root->left);
	preorder(root->right);
}

void levelOrder(node* root){          // its just like breadth first search
	if(root==NULL) return;
	queue<node*> Q;                          //  O(n)
	Q.push(root);
	while(!Q.empty()){
		node* curr = Q.front(); 
		Q.pop();       
		cout<<curr->data<<endl;
		if(curr->left!=NULL) Q.push(curr->left);
		if(curr->right!=NULL) Q.push(curr->right);
	}
}

bool Search(node* root,int data){                    //  O(logn)
	if(root==NULL) return false;
	else if(data == root->data) return true;
	else if(data<root->data) Search(root->left,data);
	else Search(root->right,data);
}

void deleteTree(node* node){               //  O(n)
	if(node==NULL) return;      // using postorder travsersal because we want to first delete the leafs then its parents
	deleteTree(node->left);
	deleteTree(node->right);
	delete node;
}
void deleteNode(node *root,int key){
	if(root==NULL) return;
	if(key<root->key)
	deleteNode(root->left,key);
	else if(key>root->key)
	deleteNode(root->right,key);
	else{                            //  if key == root->key
		if(root->left==NULL){        
			node* tmp=root;
			root = root->right;
			delete tmp;
		}
		else if(root->right==NULL){
			node* tmp=root;
			root = root->left;
			delete tmp;
		}
		else{                          //  when both its child exits then find its inorder successor.  Note: we can also find its inorder predecessor 
			node* tmp = root->right;   //  go to the right child of the node to be deleted and then find the leftmost node to it.
			while(tmp->left!=NULL){     
				tmp=tmp->left;
			}
			root->data = tmp->data;        //  copy its data to the node to be deleted.
			deleteNode(root->right,tmp->data);  //  delete its inorder successor 
		}
	}
}

node* findMin(node* root){      //  minimum value node will be the leftmost child.
	if(root==NULL) return root;     //  we can also do it recursively: if(root->left==NULL) return root;  else findMin(root->left);
 	while(root->left!=NULL)
	root = root->left;
	return root;
}


