/*Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
 

Constraints:

1 <= s.length <= 20
1 <= p.length <= 20
s contains only lowercase English letters.
p contains only lowercase English letters, '.', and '*'.
It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        
        int dp[n+1][m+1];
        memset(dp, 0, sizeof(dp));
        dp[n][m] = 1;
        
        for (int i = n; i >= 0; --i) {
            for (int j = m-1; j >= 0; --j) {
                int first_match = i < n && (s[i] == p[j] or p[j] == '.');
                
                if (j+1 < m and p[j+1] == '*') {
                    // if pattern starts with ** then skip 2 chars from pattern 
                    // or if pattern starts with .* or c*, where c is some character
                    dp[i][j] = dp[i][j+2] or (first_match and dp[i+1][j]);
                }
                else {
                    dp[i][j] = first_match and dp[i+1][j+1];
                }
            }
        }
        
        return dp[0][0];
    }
};