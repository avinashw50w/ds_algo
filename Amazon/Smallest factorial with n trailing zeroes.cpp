/*Smallest number with at least n trailing zeroes in factorial
Last Updated: 30-04-2018
Given a number n. The task is to find the smallest number whose factorial contains at least n trailing zeroes.

Examples :

Input : n = 1
Output : 5
1!, 2!, 3!, 4! does not contain trailing zero.
5! = 120, which contains one trailing zero.

Input : n = 6
Output : 25*/
// 5! has 1 zeroes
// 10! has 2 zeroes
// 15! has 3 zeroes
// 20! has 4 zeroes
// ....
// so n! has  n/5 zeroes
// do binary search and find the minimum such no

// return true if n has atleast x no of zeroes
bool check(int n, int x) {
    int cnt = 0;
    while (n) {
        cnt += n / 5;
        n /= 5;
    }

    return cnt >= x;
}

int solve(int n) {
    int l = 1, r = 5 * n;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (check(m, n)) r = m;
        else l = m + 1;
    }

    return l;
}