/*Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode"
return 2.*/

int firstUniqChar(string s) {
    unordered_map<char, int> f;
    for (char c : s) f[c]++;
    for (int i = 0; i < s.size(); ++i) if (f[s[i]] == 1) return i;
    return -1;
}