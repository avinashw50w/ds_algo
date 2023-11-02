/*
Given a singly linkedlist like:
1->4->3->2

You have to calculate the sum of first and last elements like:
1+2 = 3
4+3 = 7

Then output the maximum sum. Here maximum sum is 7.

Space complexity should be O(1).
No constraint on time complexity.

step 1 : count the number of nodes in the list - O(N) time
step 2 : break the list from middle and reverse the second half of linked list - O(N) time and O(1) space if we ignore recursion
step 3 : after step 2 above, the lists would be like 1-->4 and 2-->3
now, this is as good as traversing two lists simultaneously and computing the sums and checking for max - O(N) time

step 4 : if needed, restore the structure of the linked list back - O(N) time again
*/

int max_val;
ListNode* tmp;

void maxPair(ListNode* p) {
    if(p == NULL) {
        return;
    }
    maxPair(p->next);
    max_val = max(max_val, p->val + tmp->val);
    tmp = tmp->next;
}
void solve(ListNode* head)
{
    max_val = INT_MIN;
    tmp = head;
    maxPair(head);
    cout<<"Result is "<<max_val<<"\n";
}

// another way

public int maxPairList(ListNode head) {
    ListNode fast = head;
    ListNode slow = head;
    ListNode current = head;
    while(fast != null && fast.next != null) {
        slow = slow.next;
        fast = fast.next.next;
    }
    slow = reverse(slow);
    int max = Integer.MIN_VALUE;
    while (slow != null) {
        int sum = slow.val + current.val;
        if (max < sum) {
            max = sum;
        }
        slow = slow.next;
        current = current.next;
    }
    return max;
}

public ListNode reverse(ListNode head) {

    ListNode prev = null;
    ListNode next = head;
    ListNode current = head;

    while(current != null) {
        next = next.next;
        current.next = prev;
        prev = current;
        current = next;
    }

    return prev;
}