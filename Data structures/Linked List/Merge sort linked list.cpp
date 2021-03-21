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
    void breakIntoHalf(ListNode *&head, ListNode *&a, ListNode *&b) {
        
    }
    
    ListNode *merge(ListNode *a, ListNode *b) {
        if (!a) return b;
        if (!b) return a;
        ListNode *res = NULL;
        if (a->val <= b->val) {
            res = a;
            res->next = merge(a->next, b);
        }
        else {
            res = b;
            res->next = merge(a, b->next);
        }
        
        return res;
    }

    
    ListNode* sortList(ListNode* head) {
        if (!head or !head->next) return head;
        ListNode *p = head, *s = head, *f = head;
        while (f and f->next) {
            p = s;
            s = s->next;
            f = f->next->next;
        }
        p->next = NULL;
        
        ListNode *a = sortList(head);
        ListNode *b = sortList(s);
        
        return merge(a, b);
    }
        
};