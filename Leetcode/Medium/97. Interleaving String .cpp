/*Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.*/

class Solution {
    map<string, bool> mp;
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.empty() and s2.empty() and s3.empty()) return true;
        if (s3.empty()) return false;
        string key = s1 + "|" + s2 + "|" + s3;
        if (mp.count(key)) return mp[key];
        bool x = s1.size() and s1[0] == s3[0] and isInterleave(s1.substr(1), s2, s3.substr(1));
        bool y = s2.size() and s2[0] == s3[0] and isInterleave(s1, s2.substr(1), s3.substr(1));
        
        return mp[key] = x | y;
    }
};