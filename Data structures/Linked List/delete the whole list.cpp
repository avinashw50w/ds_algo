// delete the whole list

void delete_list(node** head){
	node* curr=*head;
	node* temp;
	while(curr!=NULL){
		temp = curr->next;
		delete curr;
		curr = temp;
	}
	*head=NULL;
}
