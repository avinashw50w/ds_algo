/*Given two sequences A, B, find out number of unique ways in sequence A, to form a subsequence of A 
that is identical to the sequence B. Transformation is meant by converting string A 
(by removing 0 or more characters) to string B.

Examples:

Input : A = "abcccdf", B = "abccdf"
Output : 3
Explanation : Three ways will be -> "ab.ccdf", 
"abc.cdf" & "abcc.df" .
"." is where character is removed. 

Input : A = "aabba", B = "ab"
Output : 4
Expalnation : Four ways will be -> "a.b..",
 "a..b.", ".ab.." & ".a.b." .
"." is where characters are removed.*/ 
/*ize, where m is size of string B and n is size of string A.
dp[i][j] gives the number of ways of transforming string A[0…j] to B[0…i].

Case 1 : dp[0][j] = 1, since placing B = “” with any substring of A would have only 1 solution 
which is to delete all characters in A.
Case 2 : when i > 0, dp[i][j] can be derived by two cases:
Case 2.a : if B[i] != A[j], then the solution would be to ignore the character A[j] 
and align substring B[0..i] with A[0..(j-1)]. Therefore, dp[i][j] = dp[i][j-1].
Case 2.b : if B[i] == A[j], then first we could have the solution in case a), 
but also we could match the characters B[i] and A[j] and place the rest of them 
(i.e. B[0..(i-1)] and A[0..(j-1)]. As a result, dp[i][j] = dp[i][j-1] + dp[i-1][j-1].*/

#include <bits/stdc++.h> 
using namespace std; 
  
int countTransformation(string a, string b) 
{ 
    int n = a.size(), m = b.size(); 
 
    if (m == 0) 
        return 1; 
  
    int dp[m + 1][n + 1]; 
    memset(dp, 0, sizeof(dp)); 
  
  	for (int i = 0; i < n; ++i) dp[0][i] = 1;

    for (int i = 1; i <= m; i++) { 
        for (int j = 1; j <= n; j++) {
        	if (a[j-1] != b[i-1]) dp[i][j] = dp[i][j-1];
        	else dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
        } 
    } 
  
    return dp[m][n]; 
} 
  
// Driver code 
int main() 
{ 
    string a = "aabba", b = "ab"; 
    cout << countTransformation(a, b) << endl; 
    return 0; 
} 