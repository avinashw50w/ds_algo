

int getMiddle(struct Node *head)
{
    if(head == NULL) return -1;
    Node *slow, *fast;
    slow = fast = head;
   
    while(fast and fast->next) {
       slow = slow->next;
       fast = fast->next->next;
   }
   return slow->data;
}