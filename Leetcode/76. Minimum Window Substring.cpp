/*Given two strings s and t, return the minimum window in s which will contain all the
 characters in t. If there is no such window in s that covers all characters in t, return the 
 empty string "".

Note that If there is such a window, it is guaranteed that there will always be only one unique 
minimum window in s.

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"*/

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length(), m = t.length();
        if (m > n) return "";
        map<char,int> ft, fs;
        for (char c: t) ft[c]++;
        int cnt = 0, st = 0, minlen = n+1;
        string ans = "";
        for (int i = 0; i < n; ++i) {
            fs[s[i]]++;
            if (ft[s[i]] and fs[s[i]] <= ft[s[i]]) cnt++;
            if (cnt == m) {
                while (ft[s[st]] == 0 or fs[s[st]] > ft[s[st]]) {
                    if (fs[s[st]] > ft[s[st]]) {
                        fs[s[st]]--;
                    }
                    st++;
                }
                if (minlen > i-st+1) {
                    minlen = i-st+1;
                    ans = s.substr(st, i-st+1);
                }
            }
        }
        
        return ans;
    }
};