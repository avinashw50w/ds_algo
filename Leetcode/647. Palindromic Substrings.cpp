/*Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".*/

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        multiset<string> p;
        
        for (int i = 1; i < n; ++i) {
            int l = i-1, r = i;
            while (l >= 0 and r < n and s[l] == s[r]) 
                p.insert(s.substr(l, r-l+1)), l--, r++;
            
            l = i-1; r = i+1;
            while (l >= 0 and r < n and s[l] == s[r]) 
                p.insert(s.substr(l, r-l+1)), l--, r++;
        }
        
        return n + p.size();
    }
};