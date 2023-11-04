/*Given an integer, return its base 7 string representation.

Example 1:
Input: 100
Output: "202"
Example 2:
Input: -7
Output: "-10"
Note: The input will be in range of [-1e7, 1e7].*/

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        bool neg = num < 0;
        num = abs(num);
        string l = "01234567";
        string ans = "";
        while (num) {
            ans = l[num % 7] + ans;
            num /= 7;
        }

        return neg ? "-" + ans : ans;
    }
};