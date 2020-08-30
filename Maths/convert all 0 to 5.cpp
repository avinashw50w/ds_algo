/*You are given an integer N. You need to convert all zeroes of N to 5.

Example 1:

Input:
N = 1004
Output: 1554
Explanation: There are two zeroes in 1004
on replacing all zeroes with "5", the new
number will be "1554".*/

int convertFive(int n) {
    int d = 10, p = 1;

    while (n / p) {
        int t = n % d;
        if (t / p == 0) n += 5 * p;
        p *= 10;
        d *= 10;
    }
    return n;
}