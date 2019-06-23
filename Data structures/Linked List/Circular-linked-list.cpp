/* structure for a node */
struct node
{
    int data;
    struct node *next;
};
 
/* Function to insert a node at the begining of a Circular
   linked list */
void push(struct node **head_ref, int data)
{
    struct node *tmp = new node();
    struct node *curr = *head_ref;
    tmp->data = data;
    tmp->next = *head_ref;
 
    /* If linked list is not NULL then set the next of last node */
    if (*head_ref != NULL)
    {
        while (curr->next != *head_ref)
            curr = curr->next;
        curr->next = tmp;
    }
    else
        tmp->next = tmp; /*For the first node */
 
    *head_ref = tmp;
}
 
/* Function to print nodes in a given Circular linked list */
void printList(struct node *head)
{
    struct node *temp = head;
    if (head != NULL)
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        while (temp != head);
    }
}
 
/* Driver program to test above functions */
int main()
{
    /* Initialize lists as empty */
    struct node *head = NULL;
 
    /* Created linked list will be 11->2->56->12 */
    push(&head, 12);
    push(&head, 56);
    push(&head, 2);
    push(&head, 11);
 
    printf("Contents of Circular Linked List\n ");
    printList(head);
 
    return 0;
}