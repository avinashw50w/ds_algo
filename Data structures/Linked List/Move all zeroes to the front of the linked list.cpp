/*Move all zeros to the front of the linked list
1.5
Given a linked list. the task is to move all 0’s to the front of the linked list. 
The order of all other element except 0 should be same after rearrangement.

Examples:

Input : 0 1 0 1 2 0 5 0 4 0
Output :0 0 0 0 0 1 1 2 5 4

Input :1 1 2 3 0 0 0 
Output :0 0 0 1 1 2 3 

A simple solution is to store all linked list element in an array. Then move all elements of array to beginning. 
Finally copy array elements back to linked list.

An efficient solution is to traverse the linked list from second node. For every node with 0 value,
 we disconnect it from its current position and move the node to front.*/

void push(struct Node **head_ref, int new_data) {
  struct Node *new_node = new Node;
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}
 
/* moving zeroes to the begining in linked list */
void moveZeroes(struct Node **head) {
  if (*head == NULL)
    return;
 
  // Traverse the list from second node.
  struct Node *temp = (*head)->next, *prev = *head;
  while (temp != NULL) {
 
    // If current node is 0, move to
    // beginning of linked list
    if (temp->data == 0) {
 
      // Disconnect node from its
      // current position
      Node *curr = temp;
      temp = temp->next;
      prev->next = temp;
 
      // Move to beginning
      curr->next = (*head);
      *head = curr;
    }
 
    // For non-zero values
    else {
      prev = temp;
      temp = temp->next;
    }
  }
}