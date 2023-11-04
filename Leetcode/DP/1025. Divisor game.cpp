/*Alice and Bob take turns playing a game, with Alice starting first.

Initially, there is a number N on the chalkboard.  On each player's turn, that player makes a move consisting of:

Choosing any x with 0 < x < N and N % x == 0.
Replacing the number N on the chalkboard with N - x.
Also, if a player cannot make a move, they lose the game.

Return True if and only if Alice wins the game, assuming both players play optimally.

 

Example 1:

Input: 2
Output: true
Explanation: Alice chooses 1, and Bob has no more moves.*/

class Solution {
public:
    bool divisorGame(int N) {
        bool dp[1001];
        memset(dp, false, sizeof(dp));
        
        dp[0] = dp[1] = false;
        dp[2] = true;
        
        for (int i = 3; i <= N; ++i) {
            for (int j = 1; j < i; ++j) {
                if (i % j == 0 and dp[i - j] == false) 
                    dp[i] = true;
            }
        }
        
        return dp[N];
    }
};