/*Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
Input: head = [1,2,3,4]
Output: [2,1,4,3]*/
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
    bool enoughNodes(ListNode *head, int k) {
        while (k and head) {
            k--;
            head = head->next;
        }
        return k == 0;
    }

    ListNode* reverseK(ListNode *head, int k) {
        if (!head or !enoughNodes(head, k)) return head;
        ListNode *prev = NULL, *curr = head;

        int cnt = 0;
        while (cnt < k) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }

        head->next = reverseK(curr, k);
        return prev;
    }
    ListNode* swapPairs(ListNode* head) {
        return reverseK(head, 2);
    }
};