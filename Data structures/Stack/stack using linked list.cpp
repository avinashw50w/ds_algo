#include<iostream>
using namespace std;
struct node{
	int data;
	node* next;
}
void push(node** head,int val){
	node* tmp = new node();
	tmp->data = val;
	tmp->next = *head;
	*head = tmp;
}
void pop(node** head){
	if(*head==NULL) return;
	node* tmp = (*head)->next;
	delete *head;
	*head = tmp;
}
int top(node** head){
	if(*head==NULL)
		cout<<"Empty Stack!";
else return (*head)->data;
}
void deleteStack(node** head){
	node *tmp;
	while(*head){
		tmp = (*head)->next;
		delete *head;
		*head = tmp;
	}
}

int main(){
	node* head = NULL;
}

