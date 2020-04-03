/*Given a linked list, write a function to reverse every k nodes (where k is an input to the function).

Example:
Inputs:  1->2->3->4->5->6->7->8->NULL and k = 3 
Output:  3->2->1->6->5->4->8->7->NULL. 

Inputs:   1->2->3->4->5->6->7->8->NULL and k = 5
Output:  5->4->3->2->1->8->7->6->NULL. 

Algorithm: reverse(head, k)
1) Reverse the first sub-list of size k. While reversing keep track of the next node and previous node. 
Let the pointer to the next node be next and pointer to the previous node be prev. See this post for reversing a linked list.
2) head->next = reverse(next, k) /* Recursively call for rest of the list and link the two sub-lists 
3) return prev  prev becomes the new head of the list*/

struct node *reverse (struct node *head, int k)
{
    struct node* current = head;
    struct node* next = NULL;
    struct node* prev = NULL;
    int count = 0;   
     
    /*reverse first k nodes of the linked list */
    while (current != NULL && count < k)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
     
    /* next is now a pointer to (k+1)th node 
       Recursively call for the list starting from current.
       And make rest of the list as next of first node */
    if (next !=  NULL)
       head->next = reverse(next, k); 
 
    /* prev is new head of the input list */
    return prev;
}