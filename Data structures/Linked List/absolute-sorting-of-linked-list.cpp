/*Sort linked list which is already sorted on absolute values
Given a linked list which is sorted based on absolute values. Sort the list based on actual values.

Examples:

Input :  1 -> -10
output: -10 -> 1

Input : 1 -> -2 -> -3 -> 4 -> -5
output: -5 -> -3 -> -2 -> 1 -> 4

Input : -5 -> -10
Output: -10 -> -5

Input : 5 -> 10

A simple solution is to traverse the linked list from beginning to end. For every visited node, check if it is out of order.
If it is, remove it from its current position and insert at correct position. This is implementation of insertion sort for
linked list and time complexity of this solution is O(n*n).

A better solution is to sort the linked list using merge sort. Time complexity of this solution is O(n Log n).

An efficient solution can work in O(n) time. An important observation is, all negative elements are present in reverse order.
So we traverse the list, whenever we find an element that is out of order, we move it to the front of linked list.*/

void sortList(Node** head)
{
    // Initialize previous and current nodes
    Node* prev = (*head);
    Node* curr = (*head)->next;

    // Traverse list
    while (curr != NULL)
    {
        // If curr is smaller than prev, then
        // it must be moved to head
        if (curr->data < prev->data)
        {
            // Detach curr from linked list
            prev->next = curr->next;

            // Move current node to beginning
            curr->next = (*head);
            (*head) = curr;

            // Update current
            curr = prev;
        }
        else
            prev = curr;

        // Move current
        curr = curr->next;
    }
}
