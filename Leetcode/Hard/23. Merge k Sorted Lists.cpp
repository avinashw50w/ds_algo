/*You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
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
    ListNode* merge(ListNode *a, ListNode *b) {
        ListNode *res = NULL;
        if (a == NULL) return b;
        if (b == NULL) return a;
        if (a->val < b->val) {
            res = a;
            res->next = merge(a->next, b);
        }
        else {
            res = b;
            res->next = merge(a, b->next);
        }
        return res;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        int k = lists.size() - 1;
        while (k != 0) {
            int i = 0, j = k;
            while (i < j) {
                lists[i] = merge(lists[i], lists[j]);
                ++i; --j;
                if (i >= j) k = j;
            }
        }
        return lists[0];
    }
};