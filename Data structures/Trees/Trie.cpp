#include <bits/stdc++.h>
using namespace std;

struct Node {
	bool leaf;
	Node* ch[26];
};

Node* newNode(){
	Node* tmp = new Node();
	tmp->leaf = false;
	for (int i = 0; i < 26; i++)
		tmp->ch[i] = NULL;
	return tmp;
}


void insert(Node* root, string s) {
	int l = s.size();
	int index;
	Node *tmp = *root;
	
	for (int i = 0; i < l; i++){
		index = s[i] - 'a';
		if (tmp->ch[index] == NULL)
			tmp->ch[index] = newNode();
		tmp = tmp->ch[index];
	}
	tmp->leaf = true;
}


void search(Node* root, string s) {
	int l = s.size();
	Node* tmp = root;
	int index, found = 1;

	for (int i = 0; i < l; i++) {
		index = s[i] - 'a';
		if (tmp->ch[index] == NULL){
			found = 0; 
			break;
		}
		tmp = tmp->ch[index];
	}
	return (found);
}

int main(){
	Node *root=newNode();
	insert(&root,"avinash");
	insert(&root,"ranjan");
	search(root,"avi");
	search(root,"shankul");

	return 0;
}

