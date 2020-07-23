void solve(string s1, string s2) {
    int m = s1.size();
    int n = s2.size();
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++) {
        dp[0][i] = i;
    }

    for (int i = 1; i <= m; i++) {
        dp[i][0] = i;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // no operation required as characters are the same
            }
            else {
                dp[i][j] = 1 + min(dp[i - 1][j - 1],     // substitution
                                   min(dp[i][j - 1],   // insertion
                                       dp[i - 1][j]));    // deletion
            }
        }
    }

    int i = m, j = n;

    while (i >= 0 and j >= 0) {
        if (s1[i - 1] == s2[j - 1]) i--, j--;
        // Replace
        else if (dp[i][j] == dp[i - 1][j - 1] + 1)
        {
            cout << "change " << s1[i - 1]
                 << " to " << s2[j - 1] << endl;
            i--;
            j--;
        }

        // Delete the character
        else if (dp[i][j] == dp[i - 1][j] + 1)
        {
            cout << "Delete " << s1[i - 1] << endl;
            i--;
        }

        // Add the character
        else if (dp[i][j] == dp[i][j - 1] + 1)
        {
            cout << "Add " << s2[j - 1] << endl;
            j--;
        }
    }
}