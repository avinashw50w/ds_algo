/* The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted 
into a different digit string.
To determine how you "say" a digit string, split it into the minimal number of substrings such that each 
substring contains exactly one unique digit. Then for each substring, say the number of digits, then say 
the digit. Finally, concatenate every said digit.

For example, the saying and conversion for digit string "3322251":


Input: n = 4
Output: "1211"
Explanation:
countAndSay(1) = "1"
countAndSay(2) = say "1" = one 1 = "11"
countAndSay(3) = say "11" = two 1's = "21"
countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"*/

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 0; i < n - 1; ++i) {
            string s2 = "";
            int j = 0;
            while (j < s.size()) {
                int len = 1;
                while (j + len < s.size() and s[j] == s[j + len]) len++;
                s2 += to_string(len);
                s2 += s[j];
                j += len;
            }
            s = s2;
        }

        return s;
    }
};