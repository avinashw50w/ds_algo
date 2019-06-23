/* m : dist of the starting node of the loop from the head
  n : length of the loop
  k : dist from the starting point of the loop where both slow and fast ptr meet.

  refer image : http://d1gjlxt8vb0knt.cloudfront.net//wp-content/uploads/LinkedListCycle.jpg

Distance traveled by fast pointer = 2 * (Distance traveled 
                                         by slow pointer)

(m + n*x + k) = 2*(m + n*y + k)

Note that before meeting the point shown above, fast
was moving at twice speed.

x -->  Number of complete cyclic rounds made by 
       fast pointer before they meet first time

y -->  Number of complete cyclic rounds made by 
       slow pointer before they meet first time

From above equation, we can conclude below

    m + k = (x-2y)*n

Which means m+k is a multiple of n. 
So if we start moving both pointers again at same speed such that one pointer (say slow) begins from head node of linked list 
and other pointer (say fast) begins from meeting point. When slow pointer reaches beginning of linked list (has made m steps). 
Fast pointer would have made also moved m steps as they are now moving same pace. Since m+k is a multiple of n and fast starts from k, 
they would meet at the beginning. Can they meet before also? No because slow pointer enters the cycle first time after m steps.

Since m + k = (const) * n  => m + k = n  => m = n - k  
when slow_ptr == fast_ptr , then the slow_ptr and fast_ptr has moved distance of m+k from head.
Now move the slow_ptr to head. the fast_ptr has to move remaining n-k dist to make one complete rotation. 
Now moveing both slow and fast ptr move at the same speed, they will eventually meet at the starting point of the loop because
when slow_ptr moves a dist of m, fast_ptr also moves a dist of m, since m = n-k. So, when the fast_ptr makes one complete rotation
and reaches the starting point of the loop, slow_ptr also meets the fast_ptr at that point.*/

// A utility function to print a linked list
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->key << " ";
        head = head->next;
    }
    cout << endl;
}
 
void detectAndRemoveLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
 
    // Search for loop using slow and fast pointers
    while (fast && fast->next)
    {
        if (slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }
 
    /* If loop exists */
    if (slow == fast)
    {
        slow = head;
        while (slow != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
 
        /* since fast->next is the looping point */
        fast->next = NULL; /* remove loop */
    }
}