/*Given a linked list, determine if it has a cycle in it.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *s = head, *f = head;
        while (f and f->next) {
            s = s->next;
            f = f->next->next;

            if (s == f) return true;
        }

        return false;
    }
};