#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *next;
};

node * head = NULL;

node* newNode(int val) {
	node* tmp = head;
	tmp->data = val;
	tmp->next = NULL;
	return tmp;
}

void Insert(){
	int n;
	cout<<"\nenter the value:";
	cin>>n;
	if(head==NULL){		
		head = newNode(n);
	}
	else{
		node* curr=*head;
		while(curr->next!=NULL)
			curr=curr->next;
		curr->next = newNode(n);	
	}
}

void Insert_beg(node** head){
	int n;
	cout<<"\nEnter the value :";
	cin>>n;
	node* temp=new node();
	temp->data=n;
	temp->next=*head;
	*head=temp;
}

void update(node* head){
	int o,n;
	cout<<"\nEnter the old and the new value:";
	cin>>o>>n;
	while(head!=NULL){
		if(head->data==o) {
			head->data=n;
			break;
		}
		head=head->next;
	}
}

void Insert_at(node** head){
	int n,pos;
	cout<<"\nEnter the value and its position where to insert:";
	cin>>n>>pos;
	
	node* temp=new node();
	temp->data=n;
	if(pos==1){
		temp->next=*head;
		*head=temp;
		return;
	}
	node* curr=*head;
	for(int i=1;i<pos-1;i++)
	curr=curr->next;
	temp->next=curr->next;
	curr->next=temp;
}
void del(node** head){
	int pos;
	cout<<"\nEnter the position of value to delete:";
	cin>>pos;
	node *curr=*head;
	if(pos==1){
		*head = curr->next;
		delete curr;
		return;
	}
	for(int i=1;i<pos-1;i++)
	curr=curr->next;
	node* temp = curr->next;
	curr->next = temp->next;
	delete temp;
}


void disp(node* p){
	if(p==NULL) return;
	cout<<p->data<<" ";
	disp(p->next);
}

void rev_disp(node* p){
	if(p==NULL) return;
	rev_disp(p->next);
	cout<<p->data<<" ";
}
void print(node* head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}
int main(){
	node* head=NULL;
	int ch,val;
	do{
		cout<<"\n1.INSERT AT END\n2.INSERT AT BEGINNING\n3.INSERT AT nth POSITION\n4.UPDATE\n5.DELETE\n6.DISPLAY\n7.REVERSE DISPALY\n8.REVERSE\n0.EXIT\nEnter your choice:";
		cin>>ch;
		switch(ch){
			case 1: Insert(&head);
					print(head);
					break;
			case 2: Insert_beg(&head);
					print(head);
					break;
			case 3: Insert_at(&head);
					print(head);
					break;
			case 4: update(head);
					print(head);
					break;
			case 5: del(&head);
					print(head);
					break;
			case 6: disp(head);
					break;
			case 7: rev_disp(head);
					break;
			case 8: reverse(&head);
					print(head);
					break;
		}
		
	}while(ch);
	return 0;
}
