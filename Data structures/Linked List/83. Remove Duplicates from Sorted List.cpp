// eg 1->1->1->2  => 1->2
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return NULL;
        if (!head->next) return head;

        ListNode *curr = head;
        while (curr) {
            if (curr->next and curr->val == curr->next->val) {
                ListNode *next = curr->next;
                curr->next = curr->next->next;
                delete next;
            }
            else
                curr = curr->next;
        }

        return head;
    }
};