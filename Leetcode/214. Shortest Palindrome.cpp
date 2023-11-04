/*You are given a string s. You can convert s to a palindrome by adding characters in front of it.

Return the shortest palindrome you can find by performing this transformation.

 

Example 1:

Input: s = "aacecaaa"
Output: "aaacecaaa"
Example 2:

Input: s = "abcd"
Output: "dcbabcd"
 

Constraints:

0 <= s.length <= 5 * 104
s consists of lowercase English letters only.

IDEA: Let's first see the basic logic of this question. Given a string, out aim is to add a
 string in the front to make the new string a palindrome. Say the given string is S, the string 
 we add in the front is denoted as P, so the result string is PS, which needs to be a 
 palindrome.  According to the definition of palindrome, we can rewrite string PS into:
PS = PQP′. , we want P as short as possible, in other words, we want Q as long as possible. 
Thus, the question is now to compute the longest Qin string S, subject to Q is a palindrome.
Say, we have string  S=QP, we can append the reverse of S to S: SS′=QPP′Q′
, remember that Qis a palindrome, Q=Q′, therefore, we have: SS′=QPP′Q
, now we want to find the longest Q, where Q is the prefix of SS′, also a suffix of last 
position of SS.*/
class Solution {
public:
    int LPS(string s) {
        int n = s.size();
        vector<int> f(n);
        int ans = 0;
        int j = 0;
        for (int i = 1; i < n; ++i) {
            while (j >= 0 and s[i] != s[j]) {
                if (j >= 1) j = f[j-1];
                else j = -1;
            }
            f[i] = ++j;
        }
        
        return f[n-1];
    }
    
    bool check(string s, int len) {
        string t;
        int n = s.length();
        for (int i = n-1; i >= n-len; --i) t += s[i];
        return isPalindrome(t + s);
    }
    
    string shortestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return "";
        string t = s;
        reverse(t.begin(), t.end());
        
        int lps = LPS(s + "#" + t);
        string r = s.substr(lps);
        reverse(r.begin(), r.end());
        return r + s;
    }
};