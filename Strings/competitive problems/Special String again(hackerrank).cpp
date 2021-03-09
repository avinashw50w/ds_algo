/*A string is said to be a special string if either of two conditions is met:

All of the characters are the same, e.g. aaa.
All characters except the middle one are the same, e.g. aadaa.
A special substring is any substring of a string which meets one of those criteria. Given a string, determine how many special substrings can be formed from it.

For example, given the string s = mnonopoo, we have the following special substrings:
m, n, o, n, o, p, o, o, non, ono, opo, oo.*/

long substrCount(int n, string s) {
    int ans = 1, cnt = 1;
    // if all chars are same
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1]) {
            cnt++;
            ans += cnt;
        }
        else cnt = 1, ans++;
    }
    // when only the middle char is different
    for (int i = 1; i < n; ++i) {
        int l = i - 1, r = i + 1;
        if (s[i] != s[i - 1]) {
            while (l >= 0 and r < n and s[l] == s[r] and s[l] == s[i - 1]) {
                ans++;
                l--;
                r++;
            }
        }
    }

    return ans;
}