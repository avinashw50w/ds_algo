/*Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4*/

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

ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
	if (!a) return b;
	if (!b) return a;

	ListNode *res = NULL;
	if (a->val < b->val) {
		res = a;
		res->next = mergeTwoLists(a->next, b);
	}
	else {
		res = b;
		res->next = mergeTwoLists(a, b->next);
	}

	return res;
}

/////////////////////////////////////////////////////////////////
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode *res = NULL, *resEnd = NULL;

	while (l1 and l2) {
		if (l1->val < l2->val) {
			if (!res) res = resEnd = l1;
			else {
				resEnd->next = l1;
				resEnd = resEnd->next;
			}
			l1 = l1->next;
		}
		else {
			if (!res) res = resEnd = l2;
			else {
				resEnd->next = l2;
				resEnd = resEnd->next;
			}
			l2 = l2->next;
		}
	}

	while (l1) {
		if (!res) res = resEnd = l1;
		else {
			resEnd->next = l1;
			resEnd = resEnd->next;
		}

		l1 = l1->next;
	}
	while (l2) {
		if (!res) res = resEnd = l2;
		else {
			resEnd->next = l2;
			resEnd = resEnd->next;
		}
		l2 = l2->next;
	}

	return res;
}