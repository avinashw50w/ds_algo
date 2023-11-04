/*The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence. You can do so recursively, in other words from the previous member read off the digits, counting the number of digits in groups of the same digit.

Note: Each term of the sequence of integers will be represented as a string.
Input: 4
Output: "1211"*/

class Solution {
public:
    string solve(string s, int n) {
        if (n == 1) return s;
        string s2 = "";

        for (int i = 0; i < s.size(); ++i) {
            int cnt = 1;
            while (i < s.size() - 1 and s[i] == s[i + 1]) cnt++, i++;
            s2 += cnt + '0';
            s2 += s[i];
        }

        return solve(s2, n - 1);
    }

    string countAndSay(int n) {
        return solve("1", n);
    }
};