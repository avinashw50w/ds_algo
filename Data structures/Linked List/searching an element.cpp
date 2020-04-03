bool search(node* head,int n){
	node* curr=head;
	while(curr!=NULL){
		if(curr->key==x) return true;
		curr = curr->next;
	}
	return false;
}

bool search(node* head,int n){
	if(head==NULL) return false;
	if(head->key==n) return true;
	return search(head->next , n);
}
