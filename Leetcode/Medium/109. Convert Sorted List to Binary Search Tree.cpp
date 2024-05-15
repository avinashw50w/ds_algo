/*Given the head of a singly linked list where elements are sorted in ascending order, convert it to a 
height-balanced
 binary search tree.

 Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.*/
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(ListNode *head) {
        int cnt = 0;
        while (head) cnt++, head = head->next;
        return cnt; 
    }
    TreeNode *solve(ListNode *&head, int n) {
        if (n <= 0) return NULL;
        TreeNode *left = solve(head, n/2);
        TreeNode *root = new TreeNode(head->val);
        root->left = left;
        head = head->next;
        root->right = solve(head, n-n/2-1);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        int n = countNodes(head);
        return solve(head, n);
    }
};