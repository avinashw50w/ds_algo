/*Given the head of a linked list, rotate the list to the right by k places.*/
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
/*IDEA: let len = total lenght of list.
join head to the tail then move len-k distance from tail. then the next node will be the head*/
class Solution {
public:
    int countNodes(ListNode *head) {
        int cnt = 0;
        while (head) cnt++, head = head->next;
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        // join the last node with the head,
        // then move (total nodes - k) distance
        // then disconnect the link
        ListNode *curr = head;
        int len = 1;
        while (curr->next) len++, curr = curr->next;

        curr->next = head;

        k %= len;
        k = len - k;

        while (k--) curr = curr->next;

        head = curr->next;
        curr->next = NULL;

        return head;
    }
};