

bool areIdentical(struct node *a, struct node *b)
{
    while (a && b)
    {
        if (a->data != b->data)
            return false;

        a = a->next;
        b = b->next;
    }
 
    return (a == NULL && b == NULL);
}

// recursive
bool areIdentical(struct node *a , struct node *b) {
    if (a == NULL and b == NULL) return true;
    if (a == NULL or b == NULL) return false;
    
    return (a->data == b->data && areIdentical(a->next, b->next));
}