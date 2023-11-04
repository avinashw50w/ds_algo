/*Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

Example:

Input: 38
Output: 2 
Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
             Since 2 has only one digit, return it.*/

class Solution {
public:
    int addDigits(int num) {
        if (num <= 9) return num;
        
        int t = 0;
        while (num) {
            t += num % 10;
            num /= 10;
            t = (10 <= t and t <= 18 ? t - 10 + 1 : t);
        }
        
        return t;
    }
};