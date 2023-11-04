/*Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?*/
bool check(ListNode *&left, ListNode *right) {
    if (right == NULL) return true;
    if (!check(left, right->next)) return false;
    bool res = left->val == right->val;
    left = left->next;
    return res;
}

bool isPalindrome(ListNode* head) {
    return check(head, head);
}