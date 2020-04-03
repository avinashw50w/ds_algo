node* sortedMerge(node* a,node* b){
	node* res=NULL;
	if(a==NULL) return b;
	if(b==NULL) return a;
	
	if(a->data <= b->data){
		res=a;
		res->next = sortedMerge(a->next,b);
	}
	else{
		res=b;
		res->next = sortedMerge(a,b->next);
	}
	return res;
}

/////////////////////////////////////////////////////////////////////////
/*Method 1 (Using Dummy Nodes)
The strategy here uses a temporary dummy node as the start of the result list. 
The pointer Tail always points to the last node in the result list, so appending new nodes is easy.
The dummy node gives tail something to point to initially when the result list is empty. 
This dummy node is efficient, since it is only temporary, and it is allocated in the stack. 
The loop proceeds, removing one node from either ‘a’ or ‘b’, and adding it to tail. When
we are done, the result is in dummy.next.
*/

struct node* SortedMerge(struct node* a, struct node* b)
{
    /* a dummy first node to hang the result on */
    struct node dummy;
 
    /* tail points to the last result node  */
    struct node* tail = &dummy;
 
    /* so tail->next is the place to add new nodes
      to the result. */
    dummy.next = NULL;
    while (1)
    {
        if (a == NULL)
        {
            /* if either list runs out, use the
               other list */
            tail->next = b;
            break;
        }
        else if (b == NULL)
        {
            tail->next = a;
            break;
        }
        if (a->data <= b->data)
            MoveNode(&(tail->next), &a);
        else
            MoveNode(&(tail->next), &b);
 
        tail = tail->next;
    }
    return(dummy.next);
}
 
/* UTILITY FUNCTIONS */
/* Before calling MoveNode():
   source == {1, 2, 3}
   dest == {1, 2, 3}
 
   Affter calling MoveNode():
   source == {2, 3}
   dest == {1, 1, 2, 3} */
void MoveNode(struct node** destRef, struct node** sourceRef)
{
    /* the front source node  */
    struct node* newNode = *sourceRef;
    assert(newNode != NULL);
 
    /* Advance the source pointer */
    *sourceRef = newNode->next;
 
    /* Link the old dest off the new node */
    newNode->next = *destRef;
 
    /* Move dest to point to the new node */
    *destRef = newNode;
}
 
