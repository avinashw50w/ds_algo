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

	void print() {
		Node *curr = head;
		while (curr) cout << curr->data << " ", curr = curr->next;
		cout << endl;
	}

	void reverse() {
		Node *curr, *prev, *nxt;
		curr = head;
		prev = NULL;

		while (curr) {
			nxt = curr->next;
			curr->next = prev;
			prev = curr;
			curr = nxt;
		}

		head = prev;
	}

	void solveRec(Node *prev, Node *curr, Node *&head) {
		if (!curr->next) {
			curr->next = prev;
			head = curr;
			return;
		}

		Node *tmp = curr->next;
		curr->next = prev;
		solveRec(curr, tmp, head);
	}

	void reverseRecur() {
		if (!head) return;
		solveRec(NULL, head, head);
	}

};
int main() {
	Solution s;
	s.insert(5);
	s.insert(4);
	s.insert(3);
	s.insert(2);
	s.insert(1);
	s.print();
	s.reverse();
	s.print();
	s.reverseRecur();
	s.print();
}
