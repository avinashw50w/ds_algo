
void pairWiseSwap(struct node *head)
{
   node *tmp = head;
   
   while(tmp and tmp->next) {
       
       swap(tmp->data, tmp->next->data);
       
       tmp = tmp->next->next;
   }
}

///////////////////////////////////////////////////////////
// recursive //

void pairWiseSwap(struct node *head)
{
	if(head and head->next) {

		swap(head->data, head->next->data);

		pairWiseSwap(head->next->next);
	}
} 