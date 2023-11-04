/*Given scores of N athletes, find their relative ranks and the people with the top three 
highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

Example 1:
Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal".
For the left two athletes, you just need to output their relative ranks according to their scores.
Note:
N is a positive integer and won't exceed 10,000.
All the scores of athletes are guaranteed to be unique.*/

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& a) {
        int n = a.size();
        vector<string> ans(n);
        vector<int> b(a.begin(), a.end());
        sort(b.begin(), b.end());
    
        for (int i = 0; i < n; ++i) {
            int idx = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
            if (idx == n - 1) ans[i] = "Gold Medal";
            else if (idx == n - 2) ans[i] = "Silver Medal";
            else if (idx == n - 3) ans[i] = "Bronze Medal";
            else ans[i] = to_string(n - idx);
        }

        return ans;
    }
};