/*Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.



Example 1:

Input: "abab"
Output: True
Explanation: It's the substring "ab" twice.
Example 2:

Input: "aba"
Output: False
Example 3:

Input: "abcabcabcabc"
Output: True
Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)*/

class Solution {
public:
    int lpsLen(string s) {
        int n = s.size();
        vector<int> f(n, 0);
        int j = 0, lps = 0;
        for (int i = 1; i < n; ++i) {
            while (j >= 0 and s[i] != s[j]) {
                if (j > 0) j = f[j - 1];
                else j = -1;
            }
            ++j;
            f[i] = j;
        }

        return f[n - 1];
    }

    bool repeatedSubstringPattern(string s) {
        /* s = nT
            len(T) = len(s) - lps(s)
            so len(s) % len(T) == 0
        */
        int lenS = s.size();
        int lps = lpsLen(s);
        int lenT = lenS - lps;

        return lenS > 1 and lps > 0 and lenS % lenT == 0;
    }
};