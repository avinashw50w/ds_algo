/*Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Restrictions:
The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000]*/

class Solution {
#define min(a,b) a < b ? a : b
public:
    void reverseString(string &s, int l, int r) {
        while (l < r) swap(s[l++], s[r--]);
    }

    string reverseStr(string s, int k) {
        bool flag = true;
        for (int i = 0; i < s.size(); i += k) {
            if (flag) {
                reverseString(s, i, min(i + k - 1, s.size() - 1));
            }
            flag = !flag;
        }
        return s;
    }
};