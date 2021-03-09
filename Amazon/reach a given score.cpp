/*Consider a game where a player can score 3 or 5 or 10 points in a move. Given a total score n, find number of distinct combinations to reach the given score.
NOTE: we have to find distinct combinations
*/

int solve(int score) {
    vector<int> dp(score + 1);
    dp[0] = 1;
    for (int i : { 3, 5, 10 }) {
        for (int j = i; j <= score; ++j)
            dp[j] += dp[j - i];
    }

    return dp[score];
}

//////////////////////////////////////
int solve(int score) {
    vector<int> dp(score + 1, 0);
    dp[0] = 1;
    // no of distinct combinations to represent i with only 3
    for (int i = 3; i <= score; ++i) dp[i] += dp[i - 3];
    // no of distinct combinations to represent i with only 3 and 5
    for (int i = 5; i <= score; ++i) dp[i] += dp[i - 5];
    // no of distinct combinations to represent i with 3, 5 and 10
    for (int i = 10; i <= score; ++i) dp[i] += dp[i - 10];

    return dp[score];
}

////////////////////////////////////////////
// to find all combinations(distinct doesn't matter)
int solve(int score) {
    vector<int> dp(score + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= score; ++i) {
        if (i - 3 >= 0 and dp[i - 3]) dp[i] += dp[i - 3];
        if (i - 5 >= 0 and dp[i - 5]) dp[i] += dp[i - 5];
        if (i - 10 >= 0 and dp[i - 10]) dp[i] += dp[i - 10];
    }
}