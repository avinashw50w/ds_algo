/*In this challenge, Hannah provides a string s consisting of lowercase English letters.
Every day, for q days, she would select two integers l and r, take the substring s[l...r]
(the substring of s from index l to index r), and ask the following question:

Consider all the palindromes that can be constructed from some of the letters from s[l..r].
You can reorder the letters as you need. Some of these palindromes have the maximum length
among all these palindromes. How many maximum-length palindromes are there?

For example, if s=madamimadam, l=4 and r=7, then we have,
s[l..r] = amim => mam or mim
so ther are 2 different palindromes with maximum length, so ans is 2.
Return the ans modulo 1e9 + 7
*/

typedef long long ll;
const int maxn = 1e5 + 1;
const int mod = 1e9 + 7;
int f[26][maxn];
ll fac[maxn];

void initialize(string s) {
    int n = s.length();
    // f[c][i] : freq of char c till index i
    for (int i = 0; i < n; ++i) {
        int c = s[i] - 'a';
        f[c][i] = 1;
    }
    for (int i = 0; i < 26; ++i) {
        for (int j = 1; j < n; ++j) {
            f[i][j] += f[i][j - 1];
        }
    }

    fac[0] = fac[1] = 1LL;
    for (int i = 2; i < maxn; ++i) fac[i] = (i * fac[i - 1]) % mod;
}

ll power(int a, int b) {
    if (b == 0) return 1;
    ll x = power(a, b / 2);
    x = (x * x) % mod;
    if (b & 1) x = (x * a) % mod;
    return x;
}

/*
 * Complete the 'answerQuery' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER l
 *  2. INTEGER r
 */

int answerQuery(int l, int r) {
    --l; --r;
    map<int, int> mp;
    // eg. s = aaabbbbccc, then count the total chars used in the first half of the palindrome
    // in the above eg. a: 1, b: 2, c: 1, so total combinations = (a + b + c)!/a!b!c!
    int total = 0;
    for (int i = 0; i < 26; ++i) {
        int cnt = f[i][r] - f[i][l - 1];
        mp[i] = cnt;
        total += cnt / 2;
    }

    int odd = 0;
    ll ans = fac[total] % mod;
    for (auto p : mp) {
        if (p.second / 2)
            ans = (ans * power(fac[p.second / 2], mod - 2)) % mod;
        if (p.second & 1) odd++;
    }

    if (odd) ans = (ans * odd) % mod;
    return ans;
}