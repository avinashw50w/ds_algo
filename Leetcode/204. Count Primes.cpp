/*Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.*/

class Solution {
    typedef long long ll;
    vector<bool> p;
public:
    void sieve(int n) {
        p.assign(n, 1);
        p[0] = p[1] = false;
        for (ll i = 2; i * i <= n; ++i) {
            if (p[i]) {
                for (ll j = i * i; j <= n; j += i) p[j] = false;
            }
        }
    }

    int countPrimes(int n) {
        sieve(n + 1);
        int cnt = 0;
        for (int i = 1; i < n; ++i) cnt += p[i];
        return cnt;
    }
};