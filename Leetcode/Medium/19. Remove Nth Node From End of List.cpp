/**Given the head of a linked list, remove the nth node from the end of the list and return its head*/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n == 0 or !head) return NULL;
        ListNode *curr1 = head;
        int i = 0;
        while (i < n) {
            curr1 = curr1->next;
            i++;
        }

        ListNode *curr = head, *prev = NULL;
        while (curr1) {
            prev = curr;
            curr = curr->next;
            curr1 = curr1->next;
        }
        // the head needs to be deleted
        if (!prev) {
            ListNode *newHead = head->next;
            delete head;
            return newHead;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;

        return head;
    }
};