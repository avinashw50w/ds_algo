#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *next;
};

class Solution {
	Node *head;
public:
	Solution(): head(NULL) {}

	Node *getHead() {
		return this->head;
	}

	Node* newNode(int val) {
		Node *tmp = new Node;
		tmp->next = NULL;
		tmp->data = val;
		return tmp;
	}

	void insert(int val) {
		Node *tmp = newNode(val);
		tmp->next = head;
		head = tmp;
	}	
};

int main() {
	Solution s;
	s.insert(5);
	s.insert(4);
	s.insert(2);
	s.insert(4);
	s.insert(5);
}