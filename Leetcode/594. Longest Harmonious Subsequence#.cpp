/*We define a harmounious array as an array where the difference between its maximum value and its minimum value is exactly 1.

Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.

Example 1:

Input: [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].


Note: The length of the input array will not exceed 20,000.*/

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> f;
        int ans = 0;
        for (int e : nums) {
            if (f[e - 1])
                ans = max(ans, f[e] + f[e - 1] + 1);
            if (f[e + 1])
                ans = max(ans, f[e] + f[e + 1] + 1);
            f[e]++;
        }

        return ans;
    }
};