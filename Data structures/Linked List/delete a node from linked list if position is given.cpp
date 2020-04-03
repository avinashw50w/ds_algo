
void deleteNode(struct node **head_ref, int position)
{
   if (*head_ref == NULL)
      return;
 
   struct node* temp = *head_ref;
 
    // If head needs to be removed
    if (position == 0)
    {
        *head_ref = temp->next;   // Change head
        free(temp);               // free old head
        return;
    }
 
    for (int i=0; temp!=NULL && i<position-1; i++)
         temp = temp->next;
 
    // If position is more than number of ndoes
    if (temp == NULL || temp->next == NULL)
         return;
 
    struct node *next = temp->next->next;
 
    free(temp->next);  // Free memory
 
    temp->next = next;  // Unlink the deleted node from list
}