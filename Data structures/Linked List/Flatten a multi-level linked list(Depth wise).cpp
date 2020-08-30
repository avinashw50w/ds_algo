/*Flatten a multi-level linked list | Set 2 (Depth wise)
We have discussed flattening of a multi-level linked list where nodes have two pointers down and next.
How to flatten a linked list when we always need to process down pointer before next at every node.

Input:
1 - 2 - 3 - 4
    |
    7 -  8 - 10 - 12
    |    |    |
    9    16   11
    |    |
    14   17 - 18 - 19 - 20
    |                    |
    15 - 23             21
         |
         24

Output:
Linked List to be flattened to
1 - 2 - 7 - 9 - 14 - 15 - 23 - 24 - 8 - 16 - 17 - 18 - 19 - 20 - 21 - 10 - 11 - 12 - 3 - 4
Note : 9 appears before 8 (When we are
at a node, we process down pointer before
right pointer)
Source : Oracle Interview

We strongly recommend you to minimize your browser and try this yourself first.

If we take a closer look, we can notice that this problem is similar to tree to linked list conversion. We recursively flatten a linked list with following steps.

1) If node is NULL, return NULL.
2) Store next node of current node (used in step 4).
3) Recursively flatten down list. While flattening, keep track of last visited node, so that the next list can be linked after it.
4) Recursively flatten next list (we get the next list from pointer stored in step 2) and attach it after last visited node.*/

struct Node {
    int data;
    struct Node *next, *down;
};

Node *last; // to keep track of the last visited node

Node* flatten(Node *head) {

    if (head == NULL) return;

    last = head;

    Node *next = head->next;

    if (head->down)
        head->next = flatten(head->down);

    if (next)
        last->next = flatten(next);

    return head;
}