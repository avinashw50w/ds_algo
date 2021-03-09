/*Coin game winner where every player has three choices
A and B are playing a game. At the beginning there are n coins. Given two more numbers x and y.
 In each move a player can pick x or y or 1 coins. A always starts the game.
 The player who picks the last coin wins the game. For a given value of n,
 find whether A will win the game or not if both are playing optimally.

 IDEA: let dp[i] = true if player wins when there are i coins left, otherwise false.
 So if we are left with i coins, then we need to remove such no of coins j from i
 such that the opponent loses on remaining i - j coins, ie, i-j is the losing position
*/

// returns true if n is the winning position otherwise returns false
// so if n is the winning position, then any player who starts the game wins.
bool solve(int n, int x, int y) {
	vector<int> dp(n + 1, 0);
	dp[1] = true;
	dp[x] = true;
	dp[y] = true;

	for (int i = 1; i <= n; ++i) {
		if (dp[i - 1] == false) dp[i] = true;
		if (i - x >= 0 and dp[i - x] == false) dp[i] = true;
		if (i - y >= 0 and dp[i - y] == false) dp[i] = true;
	}

	return dp[n];
}

