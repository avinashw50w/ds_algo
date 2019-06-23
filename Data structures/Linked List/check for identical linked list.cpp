

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