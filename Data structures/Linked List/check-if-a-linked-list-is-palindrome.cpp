
int check(node **left, node *right)
{
	if(right == NULL) return true;

	if(!check(left, right->next)) return false;

	bool flag = ((*left)->data == right->data);

	*left = (*left)->next;

	return flag;
}

/////////////////////////////////////////////////////////////////////

/*METHOD 2 (By reversing the list)
This method takes O(n) time and O(1) extra space.
1) Get the middle of the linked list.
2) Reverse the second half of the linked list.
3) Check if the first half and second half are identical.
4) Construct the original linked list by reversing the second half again and attaching it back to the first half

To divide the list in two halves, method 2 of this post is used.
When number of nodes are even, the first and second half contain exactly half nodes. The challenging thing in this method is to
handle the case when number of nodes are odd. We don’t want the middle node as part of any of the lists as we are going to
compare them for equality. For odd case, we use a separate variable ‘midnode’.

CJava
/* Program to check if a linked list is palindrome */

/* Link list node */
struct node
{
    char data;
    node* next;
};

/* Function to check if given linked list is
  palindrome or not */
bool isPalindrome(struct node *head)
{
    node *slow_ptr = head, *fast_ptr = head;
    node *second_half, *prev_of_slow_ptr = head;
    node *midnode = NULL;  // To handle odd size list
    bool res = true; // initialize result

    if (head && head->next)
    {
        /* Get the middle of the list. Move slow_ptr by 1
          and fast_ptrr by 2, slow_ptr will have the middle
          node */
        while (fast_ptr && fast_ptr->next)
        {
            fast_ptr = fast_ptr->next->next;

            /*We need previous of the slow_ptr for
             linked lists  with odd elements */
            prev_of_slow_ptr = slow_ptr;
            slow_ptr = slow_ptr->next;
        }


        /* fast_ptr would become NULL when there are even elements in list.
           And not NULL for odd elements. We need to skip the middle node
           for odd case and store it somewhere so that we can restore the
           original list*/
        if (fast_ptr != NULL) // for list of odd length
        {
            midnode = slow_ptr;
            slow_ptr = slow_ptr->next;
        }

        // Now reverse the second half and compare it with first half
        second_half = slow_ptr;
        prev_of_slow_ptr->next = NULL; // NULL terminate first half
        reverse(&second_half);  // Reverse the second half
        res = compareLists(head, second_half); // compare

        /* Construct the original list back */
         reverse(&second_half); // Reverse the second half again

          // If there was a mid node (odd size case) which
         // was not part of either first half or second half.
         if (midnode != NULL)
         {
            prev_of_slow_ptr->next = midnode;
            midnode->next = second_half;
         }
         else  prev_of_slow_ptr->next = second_half;
    }
    return res;
}

/* Function to reverse the linked list  Note that this
    function may change the head */
void reverse(struct node** head_ref) {
    struct node* prev = NULL, *current = *head_ref, *next;
    while (current != NULL){
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

/* Function to check if two input lists have same data*/
bool compareLists(struct node* head1, struct node *head2) {
    struct node* temp1 = head1;
    struct node* temp2 = head2;

    while (temp1 && temp2) {
        if (temp1->data != temp2->data) {
			return false;
        }
		temp1 = temp1->next;
		temp2 = temp2->next;
    }

	return temp1 == NULL && temp2 == NULL;
}

/* Push a node to linked list. Note that this function
  changes the head */
void push(node** head_ref, char new_data) {
    node* new_node = new node();
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
