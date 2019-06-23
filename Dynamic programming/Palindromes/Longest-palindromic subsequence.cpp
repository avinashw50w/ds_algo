/*Given a sequence, find the length of the longest palindromic subsequence in it. For example, if the given sequence is “BBABCBCAB”, then the output should be 
7 as “BABCBAB” is the longest palindromic subseuqnce in it. “BBBBB” and “BBCBB” are also palindromic subsequences of the given sequence, but not the longest ones.

The naive solution for this problem is to generate all subsequences of the given sequence and find the longest palindromic subsequence. This solution is 
exponential in term of time complexity. Let us see how this problem possesses both important properties of a Dynamic Programming (DP) Problem and can efficiently 
solved using Dynamic Programming.

1) Optimal Substructure: 
Let X[0..n-1] be the input sequence of length n and L(0, n-1) be the length of the longest palindromic subsequence of X[0..n-1].

If last and first characters of X are same, then L(0, n-1) = L(1, n-2) + 2.
Else L(0, n-1) = MAX (L(1, n-1), L(0, n-2)).

Following is a general recursive solution with all cases handled.

// Everay single character is a palindrom of length 1
L(i, i) = 1 for all indexes i in given sequence

// IF first and last characters are not same
If (X[i] != X[j])  L(i, j) =  max{L(i + 1, j),L(i, j - 1)} 

// If there are only 2 characters and both are same
Else if (j == i + 1) L(i, j) = 2  

// If there are more than two characters, and first and last 
// characters are same
Else L(i, j) =  L(i + 1, j - 1) + 2 */

int fun(string s, int i, int j) {
	if(i == j) return 1;

	if(s[i] == s[j] and j-i == 1) return 2;

	if(s[i] == s[j]) return fun(s, i+1, j-1) + 2;

	else return max(fun(s, i+1,j), fun(s, i, j-1));
}

// top down // 

int fun(string s, int i, int j) {
	
	if(i > j) return 0;
	
	if(i == j) return 1;
	
	if(dp[i][j] != -1) return dp[i][j];

	if(s[i] == s[j] and j-i == 1) return 2;

	if(s[i] == s[j]) return dp[i][j] = fun(s, i+1, j-1) + 2;

	else return dp[i][j] = max(fun(s, i+1,j), fun(s, i, j-1));
}

// bottom up // 

int fun(string s, int n) {
	int dp[n][n] = {};

	for(int i = 0; i < n; ++i) dp[i][i] = 1;

	for(int L = 2; L < n; ++L) {
		for(int i = 0; i < n-L+1; ++i) {
			int j = i+L-1;
			if(s[i] == s[j] and j-i == 1) 
				dp[i][j] = 2;
			else if(s[i] == s[j]) 
				dp[i][j] = dp[i+1][j-1] + 2;
			else 
				dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
		}
	}

	return dp[0][n-1];
}

/////////////////////////////////////////////////////////////////////////
// another way to do is :
int lps(string S) {
  int n = S.size();
  int dp[n+2][n+2];
  memset(dp, 0, sizeof(dp));

        for(int len = n; len >= 1; len--) 
            for(int i = 1; i + len - 1 <= n; i++) {
                int j = i + len - 1;
                dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j + 1]));
              
                if(S[i - 1] == S[j - 1]) 
                  dp[i][j] = max(dp[i][j], dp[i - 1][j + 1] + 1 + (i != j));
            }
    int ans = 0;
    rep(i, 1, n+1) ans = max(ans, dp[i][i]);
	
	return ans; 
 }
 // the advantage of using this method is that the middle character of the lps lies where dp[i][i] is maximum
 // so we can simply find its middle character
 
 /* output : 
0 0 0 0 0 0 0 0 
0 2 2 2 2 2 2 0 
0 0 3 2 2 2 2 0 
0 0 0 4 4 4 2 0 
0 0 0 0 5 4 2 0 
0 0 0 0 0 4 2 0 
0 0 0 0 0 0 2 0 
0 0 0 0 0 0 0 0 
 */
