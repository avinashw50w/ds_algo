
void pairWiseSwap(struct node *head)
{
    node *tmp = head;

    while (tmp and tmp->next) {

        swap(tmp->data, tmp->next->data);

        tmp = tmp->next->next;
    }
}

///////////////////////////////////////////////////////////
// recursive //

void pairWiseSwap(struct node *head)
{
    if (head and head->next) {

        swap(head->data, head->next->data);

        pairWiseSwap(head->next->next);
    }
}
///////////////////////////////////////////
// If we need to change links to swap
// eg.1->2->3->4->5->6->7
//    2->1->4->3->6->5->7

Node* swapNodes(Node *head) {
    if (!head or !head->next) return NULL;
    Node *prev = head, *curr = head->next;

    while (true) {
        Node *next = curr->next;
        curr->next = prev;

        if (!next or !next->next) {
            prev->next = NULL;
            return;
        }

        prev->next = next->next;
        prev = next;
        curr = prev->next;
    }

    return head;
}