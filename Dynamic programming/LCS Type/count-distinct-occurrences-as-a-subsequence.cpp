/*Count distinct occurrences as a subsequence
Given a two strings S and T, find count of distinct occurrences of T in S as a subsequence.

Examples:

Input  : S = banana, T = ban
Output : 3
T appears in S as below three subsequences.
[ban], [ba  n], [b   an]

Input  : S = geeksforgeeks, T = ge
Output : 6
T appears in S as below three subsequences.
[ge], [     ge], [g e], [g    e] [g     e]
and [     g e]

This problem can be recursively defined as below.

// Returns count of subsequences of S that match T
// m is length of T and n is length of S
subsequenceCount(S, T, n, m)

   // An empty string is subsequence of all.
   1) If length of T is 0, return 1.

   // Else no string can be a sequence of empty S.
   2) Else if S is empty, return 0.

   3) Else if last characters of S and T don't match,
      remove last character of S and recur for remaining
        return subsequenceCount(S, T, n-1, m)

   4) Else (Last characters match), the result is sum
      of two counts.

        // Remove last character of S and recur.
        a) subsequenceCount(S, T, n-1, m) +

        // Remove last characters of S and T, and recur.
        b) subsequenceCount(S, T, n-1, m-1)  */

int solve(string s, string t) {
    int n = s.size(), m = t.size();
    if (m > n) return 0;

    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (j == 0) dp[i][j] = 1;
            else if (i == 0) dp[i][j] = 0;
            else {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]; // either take the ith char or don't
                else
                    dp[i][j] = dp[i - 1][j]; // dont take the ith char
            }
        }
    }

    return dp[n][m];
}

