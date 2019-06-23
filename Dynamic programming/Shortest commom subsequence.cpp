/*Shortest Common Supersequence
Given two strings str1 and str2, find the shortest string that has both str1 and str2 as subsequences.

Examples:

Input:   str1 = "geek",  str2 = "eke"
Output: "geeke"

Input:   str1 = "AGGTAB",  str2 = "GXTXAYB"
Output:  "AGXGTXAYB"

We need to find a string that has both strings as subsequences and is shortest such string. If both strings have 
all characters different, then result is sum of lengths of two given strings. If there are common characters, 
then we don’t want them multiple times as the task is to minimize length. Therefore, we fist find the longest 
common subsequence, take one occurrence of this subsequence and add extra characters.


Length of the shortest supersequence  = (Sum of lengths of given two strings) - 
                                        (Length of LCS of two given strings) */


int solve(string x, string y) {

	int n = x.length(), m = y.length();

	int l = lcs(x, y);

	return ( n + m - l);
}

int lcs(string x, string y) {
	int n = x.length(), m = y.length();

	int dp[n+1][m+1];
	memset(dp, 0, sizeof(dp));

	REP(i, 1, n) {
		int ii = i&1;
		REP(j, 1, m) {
			if(x[i-1] == y[j-1])
				dp[ii][j] = 1 + dp[1-ii][j-1];
			else 
				dp[ii][j] = max(dp[1-ii][j], dp[ii][j-1]);
		}
	}

	return dp[n&1][m];
}

