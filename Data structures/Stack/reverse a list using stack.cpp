void reverse(node **head){
	stack<node*> s;
	node* temp=*head;
	while(temp!=NULL)
	s.push(temp), 
	temp = temp->next;
	
	temp=s.top();
	*head = temp;
	s.pop();
	while(!s.empty())
	temp->next = s.top(),
	s.pop(),
	temp = temp->next;
	
	temp->next = NULL;
}

