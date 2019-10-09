/*Ways of transforming one string to other by removing 0 or more characters
Given two sequences A, B, find out number of unique ways in sequence A, to form a subsequence of A that is identical 
to the sequence B. Transformation is meant by converting string A (by removing 0 or more characters) to string B.

Examples:

Input : A = "abcccdf", B = "abccdf"
Output : 3
Explanation : Three ways will be -> "ab.ccdf", 
"abc.cdf" & "abcc.df" .
"." is where character is removed. 

The idea to solve this problem is using Dynamic Programming. Construct a 2D DP matrix of m*n size, where m is size of 
string B and n is size of string A.
dp[i][j] gives the number of ways of transforming string A[0…j] to B[0…i].

Case 1 : dp[0][j] = 1, since placing B = “” with any substring of A would have
 only 1 solution which is to delete all characters in A.
Case 2 : when i > 0, dp[i][j] can be derived by two cases:
Case 2.a : if B[i] != A[j], then the solution would be to ignore the character A[j] and 
align substring B[0..i] with A[0..(j-1)]. Therefore, dp[i][j] = dp[i][j-1].
Case 2.b : if B[i] == A[j], then first we could have the solution in case a), but also we 
could match the characters B[i] and A[j] and place the rest of them (i.e. B[0..(i-1)] and A[0..(j-1)]. 
As a result, dp[i][j] = dp[i][j-1] + dp[i-1][j-1].*/


const int maxn = 1e3;
int dp[maxn][maxn];

int solve(string a, string b, int n, int m) {

	int &res = dp[n][m];
	
	if (res != -1) return res;

	if (m == 0) return 1;
	if (n == 0) return 0;

	if (a[n-1] == b[m-1])
	 	res = solve(a, b, n-1, m) + solve(a, b, n-1, m-1);
	 else 
	 	res = solve(a, b, n-1, m);

	 return res;
}

int find(string a, string b) {
	int n = a.size(), m = b.size();
	
	memset(dp, -1, sizeof(dp));

	return solve(a, b, n, m);
}
