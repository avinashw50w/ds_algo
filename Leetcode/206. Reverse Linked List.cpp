/*
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *curr = head, *next;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
        return head;
    }
};

/////////////////////////////////////////
/// Recursive solution

ListNode* reverseList(ListNode* head) {
    ListNode *prev = NULL, *curr = head;
    solve(head, prev, curr);
    return head;
}

void solve(ListNode *&head, ListNode *prev, ListNode *curr) {
    if (!curr) {
        head = prev;
        return;
    }

    ListNode *next = curr->next;
    curr->next = prev;
    solve(head, curr, next);
}