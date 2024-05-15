/*Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

eg. Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
1 -> 2 -> 3 -> 4 -> 5
1 -> 4 -> 3 -> 2 -> 5
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int i = 1;
        ListNode *curr = head, *prev = NULL;
        while (i < left) i++, prev = curr, curr = curr->next;

        ListNode *c = curr->next, *p = curr;
        i++;

        while (i <= right) {
            ListNode *next = c->next;
            c->next = p;
            p = c;
            c = next;
            i++;
        }

        if (prev != NULL) prev->next = p;
        else head = p;

        if (curr != NULL) curr->next = c;
        
        return head;
    }
};