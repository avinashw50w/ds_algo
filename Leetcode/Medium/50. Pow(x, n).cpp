/*Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25*/

class Solution {
public:
    double myPow(double x, int n) {
        long long b = (long long)n;
        bool neg = b < 0;
        if (neg) b = -b;
        double res = 1.0;
        for (; b; b>>=1, x *= x) {
            if (b & 1) res *= x;
        }

        if (neg) {
            return 1.0/res;
        }
        return res;
    }
};