

struct node * removeEveryKthNode(struct node *head, int K) {
    if (head == NULL || K == 1) return NULL;

    struct node *prev = head;
    struct node *curr = head->next;

    int index = 1;

    while (curr != NULL)
    {
        if (index % K == 0)
            // remove current node and advance pointers
            prev->next = curr->next;
          
        else
            // otherwise just advance pointers
            prev = curr;
        
		curr = curr->next;
        ++index;
    }

    return head;
}

