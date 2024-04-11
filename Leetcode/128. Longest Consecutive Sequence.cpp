/*Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
*/
class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        unordered_set<int> st;
        int n = a.size();
        for (int e: a) {
            st.insert(e);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (st.count(a[i] - 1) == 0) {
                int len = 1;
                while (st.count(a[i] + len)) len++;
                ans = max(ans, len);
            }
        }
        return ans;
    }
};