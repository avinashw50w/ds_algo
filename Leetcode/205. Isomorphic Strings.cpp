/*Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true*/

class Solution {
public:
    string hash(string s) {
        vector<int> f(255, 0);
        string res = "";
        int i = 0;
        for (char c : s) {
            if (!f[c]) f[c] = ++i;
            res += to_string(f[c]);
        }
        return res;
    }

    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        return (hash(s) == hash(t));
    }
};