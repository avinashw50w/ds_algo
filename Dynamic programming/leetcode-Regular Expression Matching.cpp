/*Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".*/

// dp[i][j] : true if s[i:] can be repsented by the regular expression p[j:], otherwise false
// a* - can be either "" or multiples of a
// so if * appears after a char, then we can either skip it or repeat it
// case 1: i+1 th char of p is '*'
//      if s[i] doesn't match with p[j]: then skip the '*' : (i, j) -> (i, j+2)
//      if s[i] matches with p[j]: then repeat '*' : (i, j) -> (i+1, j)
// case 2: ith char is '.'
//      if s[i] matches with p[j]: (i, j) -> (i+1, j+1)

class Solution {
    static const int maxn = 1e3+1;
    int dp[maxn][maxn];
public:
    bool solve(string s, string p, int i, int j) {
        if (i >= s.length() and j >= p.length()) return true;
        if (j >= p.length()) return false;

        int &res = dp[i][j];
        if (res != -1) return res;

        bool first_char_match = i < s.length() and (s[i] == p[j] or p[j] == '.');

        if (j + 1 < p.length() and p[j + 1] == '*') {
            return res = solve(s, p, i, j + 2) // replace x* with ''
                        or 
                        (first_char_match and solve(s, p, i + 1, j));
        }

        if (first_char_match) {
            return res = solve(s, p, i + 1, j + 1);
        }

        return res = 0;
    }
    
    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        return solve(s, p, 0, 0);
    }
};

////////////////////////////////////////////
// bottom up

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