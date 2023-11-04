/*The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a
dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K)
was initially positioned in the top-left room and must fight his way through the dungeon to
rescue the princess.

The knight has an initial health point represented by a positive integer.
If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers)
upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that
increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN

    -2  -3    3
    -5  -10   1
    10   30  -5(P)

IDEA:
- start from the bottom right to top left
- let dp[i][j] = minimum enery required to at (i,j) to reach the princess
    Note that dp[i][j] should always be >= 1
- so dp[i][j] = max(1, minimum energy required from right or down - energy at current position(i,j))
=> dp[i][j] = min(1, min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j])
*/

class Solution {
    const int INF = 1e9;
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();

        int dp[n + 1][m + 1];
        fill(&dp[0][0], &dp[n + 1][0], INF);

        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                int t = min(dp[i + 1][j], dp[i][j + 1]);
                t = t == INF ? 1 : t;
                dp[i][j] = max(1, t - dungeon[i][j]);
            }
        }

        return dp[0][0];
    }
};