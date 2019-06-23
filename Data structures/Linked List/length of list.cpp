int length(node* head){
	if(head==NULL) return 0;
	return 1 + length(head->next);
}

int length(node* head){
	node* curr=head;
	int cnt=0;
	while(curr!=NULL){
		cnt++;
		curr = curr->next;
	}
	return cnt;
}
