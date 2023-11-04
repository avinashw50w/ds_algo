/*Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.*/

class Solution {
public:
    string longestPalindrome(string s) {
        int mx = 1;
        int l, r, len = s.size();
        int start = 0;
        
        for (int i = 1; i < len; ++i) {
            l = i-1;
            r = i;
            while (l >= 0 and r < len and s[l] == s[r]) {
                if (r-l+1 > mx) mx = r-l+1, start = l;
                l--; r++;
            }
            
            l = i-1;
            r = i+1;
            while (l >= 0 and r < len and s[l] == s[r]) {
                if (r-l+1 > mx) mx = r-l+1, start = l;
                l--; r++;
            }
        }
        
        return s.substr(start, mx);
    }
};