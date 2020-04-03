/*Length of longest palindrome list in a linked list using O(1) extra space
4
Given a linked list, find length of the longest palindrome list that exist in that linked list.

Examples:

Input  : List = 2->3->7->3->2->12->24
Output : 5
The longest palindrome list is 2->3->7->3->2

Input  : List = 12->4->4->3->14
Output : 2
The longest palindrome list is 4->4

A simple solution could be to copy linked list content to array and then find longest palindromic subarray in array, 
but this solution is not allowed as it requires extra space.

The idea is based on iterative linked list reverse process. We iterate through given linked list and 
one by one reverse every prefix of linked list from left. 
After reversing a prefix, we find the longest common list beginning from reversed prefix and list after the reversed prefix.*/

// function for counting the common elements
int countCommon(Node *a, Node *b)
{
    int count = 0;
 
    // loop to count coomon in the list starting
    // from node a and b
    for (; a && b; a = a->next, b = b->next)
 
        // increment the count for same values
        if (a->data == b->data)
            ++count;
        else
            break;
 
    return count;
}
 
// Returns length of the longest palindrome
// sublist in given list
int maxPalindrome(Node *head)
{
    int result = 0;
    Node *prev = NULL, *curr = head;
 
    // loop till the end of the linked list
    while (curr)
    {
        // The sublist from head to current
        // reversed.
        Node *next = curr->next;
        curr->next = prev;
 
        // check for odd length palindrome
        // by finding longest common list elements
        // beginning from prev and from next (We
        // exclude curr)
        result = max(result,
                     2*countCommon(prev, next)+1);
 
        // check for even length palindrome
        // by finding longest common list elements
        // beginning from curr and from next
        result = max(result,
                     2*countCommon(curr, next));
 
        // update prev and curr for next iteration
        prev = curr;
        curr = next;
    }
    return result;
}
 