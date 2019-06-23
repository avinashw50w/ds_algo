int getNth_elem(node* head,int index){
	int cnt=0;
	node* curr=head;
	while(curr!=NULL){
		if(cnt==index) return curr->data;
		cnt++;
		curr = curr->next;
	}
}

//Get the Nth element from last
/*Method : Maintain two pointers – p1 pointer and p2 pointer. Initialize both pointers to head. 
First move p1 pointer to n nodes from head. Now move both pointers one by one until p1 pointer reaches end. 
Now p2 pointer will point to nth node from the end. Return p2 pointer.   */
 
int getNth_last_elem(node* head,int n){
	node* p1=head;
	node* p2=head;
	int cnt=0;
	if(head!=NULL){
		while(cnt<n){
			p1=p1->next;
			cnt++;
		}
		while(p1!=NULL){
			p1=p1->next;
			p2=p2->next;
		}
	}
	return p2->data;
}

// Get the middle element
/* Method : Traverse linked list using two pointers. Move one pointer by one and other pointer by two. 
When the first pointer reaches end ,the second pointer will reach middle of the linked list. */

int get_middle_elem(node* head){
	node* p1=head;
	node* p2=head;
	if(head!=NULL){
		while(p1!=NULL && p1->next!=NULL){
			p1=p1->next->next;
			p2=p2->next;
		}
	}
	return p2->data;
}
