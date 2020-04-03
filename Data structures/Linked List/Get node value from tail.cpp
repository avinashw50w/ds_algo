/*
  Get Nth element from the end in a linked list of integers
  Number of elements in the list will always be greater than N.
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int GetNode(Node *head,int positionFromTail)
{
    Node *curr1, *curr2;
    curr1 = head; curr2 = head;
    
    for(int i=0;i<positionFromTail;++i) curr1 = curr1->next;
    
    while(curr1->next!=NULL){
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    
    return curr2->data;
}

