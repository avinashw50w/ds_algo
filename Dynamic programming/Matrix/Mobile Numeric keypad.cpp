/*Mobile Numeric Keypad Problem
Given the mobile numeric keypad. You can only press buttons that are up, left, right or down
to the current button. You are not allowed to press bottom row corner buttons (i.e. * and # ).
        1   2   3
        4   5   6
        7   8   9
        *   0   #

Given a number N, find out the number of possible numbers after pressing N keys.
After each press, u can press only the adjacent buttons

Examples:
For N=1, number of possible numbers would be 10 (0, 1, 2, 3, …., 9)
For N=2, number of possible numbers would be 36
Possible numbers: 00,08 11,12,14 22,21,23,25 and so on.
If we start with 0, valid numbers will be 00, 08 (count: 2)
If we start with 1, valid numbers will be 11, 12, 14 (count: 3)
If we start with 2, valid numbers will be 22, 21, 23,25 (count: 4)
If we start with 3, valid numbers will be 33, 32, 36 (count: 3)
If we start with 4, valid numbers will be 44,41,45,47 (count: 4)
If we start with 5, valid numbers will be 55,54,52,56,58 (count: 5)
*/

// DP
int solve(int k) {
    vector<vector<char>> keypad = {
        { '1', '2', '3' },
        { '4', '5', '6' },
        { '7', '8', '9' },
        { '*', '0', '#' }
    };

    int dx[5] = { 0, 0, 1, 0, -1 };
    int dy[5] = { 0, 1, 0, -1, 0 };

    int n = keypad.size(), m = keypad[0].size();
    // dp[i][j] = no of ways to reach the number i after pressing j keys
    int dp[10][k + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < 10; ++i) {
        dp[i][1] = 1;
    }

    for (int press = 2; press <= k; ++press) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {

                if (keypad[i][j] == '*' or keypad[i][j] == '#') continue;

                int curr = keypad[i][j] - '0';

                for (int move = 0; move < 5; ++move) {
                    int ni = i + dx[move];
                    int nj = j + dy[move];
                    if (ni >= 0 and ni < n and nj >= 0 and nj < m
                            and keypad[ni][nj] != '*' and keypad[ni][nj] != '#') {
                        int next = keypad[ni][nj] - '0';
                        dp[curr][press] += dp[next][press - 1];
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 10; ++i) ans += dp[i][k];

    return ans;
}

////////////////////////////////////////////////////
// space optimized
/* the answer for the current step depends on the answer of the previous step
so take dp[10][2], where dp[i][0] stores ans for the previous step and dp[i][1] for the
current step. So if k is even, store data in dp[i][0], otherwise store in dp[i][1]
*/
int solve(int k) {
    vector<vector<char>> keypad = {
        { '1', '2', '3' },
        { '4', '5', '6' },
        { '7', '8', '9' },
        { '*', '0', '#' }
    };

    int dx[5] = { 0, 0, 1, 0, -1 };
    int dy[5] = { 0, 1, 0, -1, 0 };

    int n = keypad.size(), m = keypad[0].size();
    // dp[i][j] = no of ways to reach the number i after pressing j keys
    int dp[10][2];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < 10; ++i) {
        dp[i][1] = 1;
    }

    for (int press = 2; press <= k; ++press) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {

                if (keypad[i][j] == '*' or keypad[i][j] == '#') continue;

                int curr = keypad[i][j] - '0';
                // set the ans for this state to 0, otherwise the previous ans
                // will get added to it
                dp[curr][press & 1] = 0;

                for (int move = 0; move < 5; ++move) {
                    int ni = i + dx[move];
                    int nj = j + dy[move];
                    if (ni >= 0 and ni < n and nj >= 0 and nj < m
                            and keypad[ni][nj] != '*' and keypad[ni][nj] != '#') {
                        int next = keypad[ni][nj] - '0';
                        dp[curr][press & 1] += dp[next][press & 1 ^ 1];
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 10; ++i)
        ans += dp[i][k & 1];

    return ans;
}