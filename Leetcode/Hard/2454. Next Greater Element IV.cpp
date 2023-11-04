/*You are given a 0-indexed array of non-negative integers nums. For each integer in nums, you must find its respective second greater integer.

The second greater integer of nums[i] is nums[j] such that:

j > i
nums[j] > nums[i]
There exists exactly one index k such that nums[k] > nums[i] and i < k < j.
If there is no such nums[j], the second greater integer is considered to be -1.

For example, in the array [1, 2, 4, 3], the second greater integer of 1 is 4, 2 is 3, and that of 3 and 4 is -1.
Return an integer array answer, where answer[i] is the second greater integer of nums[i].
Example 1:

Input: nums = [2,4,0,9,6]
Output: [9,6,6,-1,-1]
Explanation:
0th index: 4 is the first integer greater than 2, and 9 is the second integer greater than 2, to the right of 2.
1st index: 9 is the first, and 6 is the second integer greater than 4, to the right of 4.
2nd index: 9 is the first, and 6 is the second integer greater than 0, to the right of 0.
3rd index: There is no integer greater than 9 to its right, so the second greater integer is considered to be -1.
4th index: There is no integer greater than 6 to its right, so the second greater integer is considered to be -1.
Thus, we return [9,6,6,-1,-1].
*/
class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& a) {
        int n = a.size();
        vector<int> next(n, -1);
        stack<int> st1, st2, tmp;
        
        for (int i = 0; i < n; ++i) {
            while (!st2.empty() and a[i] > a[st2.top()]) {
                next[st2.top()] = a[i];
                st2.pop();
            }

            while (!st1.empty() and a[i] > a[st1.top()]) {
                tmp.push(st1.top());
                st1.pop();
            }

            while (!tmp.empty()) {
                st2.push(tmp.top());
                tmp.pop();
            }
            st1.push(i);
        }

        return next;
    }
};