/*Given only a pointer/reference to a node to be deleted in a singly linked list, how do you delete it?*/
void deleteNode(struct node *node_ptr)   
{
   struct node *temp = node_ptr->next;
   node_ptr->data    = temp->data;
   node_ptr->next    = temp->next;
   free(temp);
}
 
/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
 
    /* Use push() to construct below list
    1->12->1->4->1  */
    push(&head, 1);
    push(&head, 4);
    push(&head, 1);
    push(&head, 12);
    push(&head, 1);
 
    printf("Before deleting \n");
    printList(head);
 
    /* I m deleting the head itself.
        You can check for more cases */
    deleteNode(head);
 
    printf("\nAfter deleting \n");
    printList(head);
    getchar(); 
    return 0;
}
/*
Output:
Before deleting 
1 12 1 4 1 
After deleting 
12 1 4 1 

*/