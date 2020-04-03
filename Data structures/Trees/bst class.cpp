#include<iostream>
using namespace std;

template<typename T> 
struct node{ 
    T data;
    node* left,*right;
};
class Tree{
	node* root;
	public: Tree(): root(NULL) {}
	void Insert(int n){
		if(root==NULL){
			root->data = n;
			root->left = root->right=NULL;
			return;
		}
		if(n < root->data)
			Insert(root->left);
		else
			Insert(root->right);
	}
};
