/*We are given hours, a list of the number of hours worked per day for a given employee.
A day is considered to be a tiring day if and only if the number of hours worked is (strictly) greater than 8.

A well-performing interval is an interval of days for which the number of tiring days is strictly larger than the number of non-tiring days.

Return the length of the longest well-performing interval.

Example 1:

Input: hours = [9,9,6,0,6,6,9]
Output: 3
Explanation: The longest well-performing interval is [9,9,6].
Example 2:

Input: hours = [6,6,6]
Output: 0*/

/* substitute tiring days as 1 and non-tiring days as -1. Now we have to find the longest subarray whose sum is > 0.*/
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        unordered_map<int, int> mp;
        int sum = 0, n = hours.size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            sum += hours[i] > 8 ? 1 : -1;
            if (sum > 0) ans = i+1;
            else {
                if (mp.count(sum-1))
                    ans = max(ans, i - mp[sum-1]);
                if (!mp.count(sum))
                    mp[sum] = i;
            }
        }

        return ans;
    }
};