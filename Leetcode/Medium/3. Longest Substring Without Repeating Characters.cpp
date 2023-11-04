/*Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, n = s.length();
        unordered_map<char, int> mp;
        
        for (int start = 0, end = 0; start < n; ++start) {
            while (end < n and mp[s[end]] == 0) mp[s[end++]]++;
            ans = max(ans, end - start);
            mp[s[start]]--;
        }
        
        return ans;
    }
};