#include <iostream>
using namespace std;

struct node{
	int value;
	node* ch[2];
};

node* newNode(){
	node* temp = new node();
	temp->value = 0;
	temp->ch[0] = temp->ch[1] = NULL;
	return temp;
}

void insert(node* root, int pre_xor){
	node* temp = root;
	for(int i=31; i>=0; i--){
		bool val = pre_xor & (1<<i);
		if(temp->ch[val] == NULL)
			temp->ch[val] == newNode();
		temp = temp->ch[val];
	}
	temp->value = pre_xor;
}

void query(node* root, int pre_xor){
	node* temp = root;
	for(int i=31; i>=0; i--){
		bool val = pre_xor & (1<<i);
		if(temp->ch[1-val] != NULL)
			temp = temp->ch[1-val];
		else if(temp->ch[val] != NULL)
			temp = temp->ch[val];
	}
	return pre_xor ^ temp->value;
}

int maxSubarrayXOR(int a[], int n){
	node* root = newNode();
	insert(root ,0);

	int res = -oo , pre_xor = 0;
	for(int i=0; i<n; ++i){
		pre_xor ^= a[i];
		insert(root, pre_xor);

		res = max(res , query(root, pre_xor));
	}
	return res;
}