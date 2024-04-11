/*Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
*/

ListNode* removeElements(ListNode* head, int val) {

    while (head and head->val == val) {
        head = head->next;
    }

    ListNode *prev = NULL, *curr = head;

    while (curr) {

        if (curr->val == val) {
            ListNode *tmp = curr->next;
            if (prev) prev->next = tmp;
            curr = tmp;
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}