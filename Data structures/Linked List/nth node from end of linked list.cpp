

int getNthFromLast(struct Node *head, int n)
{
       if(head == NULL) return -1;
       
       Node *curr1, *curr2;
       curr1 = curr2 = head;
       
       for(int i=0; i<n ; ++i) {
           if(curr2 == NULL) return -1;
           curr2 = curr2->next;
       }
       
       while(curr2 != NULL) {
           curr1 = curr1->next;
           curr2 = curr2->next;
       }
       
       return curr1->data;
}