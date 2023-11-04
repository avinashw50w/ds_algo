/*Write a program to find the node at which the intersection of two singly linked lists begins.
eg.  4 -> 1
            \
              8 -> 4 -> 7
            /
 5 -> 1 -> 6
*/
class Solution {
public:
    int count(ListNode *a) {
        int cnt = 0;
        ListNode *curr = a;
        while (curr) cnt++, curr = curr->next;
        return cnt;
    }

    ListNode *getIntersectionNode(int d, ListNode *a, ListNode *b) {
        ListNode *curr1 = a, *curr2 = b;
        int i;
        for (i = 0; i < d and curr1; ++i) curr1 = curr1->next;
        if (i < d) return NULL;

        while (curr1 and curr2) {
            if (curr1 == curr2) return curr1;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        return NULL;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int cnt1 = count(headA);
        int cnt2 = count(headB);

        if (cnt1 > cnt2) {
            int d = cnt1 - cnt2;
            return getIntersectionNode(d, headA, headB);
        } else {
            int d = cnt2 - cnt1;
            return getIntersectionNode(d, headB, headA);
        }

        return NULL;
    }
};