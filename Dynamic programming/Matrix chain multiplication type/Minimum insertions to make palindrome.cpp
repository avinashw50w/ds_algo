/*Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
For Example:
ab: Number of insertions required is 1. bab or aba
aa: Number of insertions required is 0. aa
abcd: Number of insertions required is 3. dcbabcd 

IDEA: 
let's say we have the string : avinash
here the first and the last char don't match, so we can either insert a at end OR h at the front 
to make it a palindrome
avinasha OR havinash
_vinash_ OR _avinas_

so dp[i][j] = 0 if i == j // cuz a single character is always a palindrome
            = 1 if i+1 == j and s[i] != s[j]
            = 1 + dp[i+1][j-1]
*/

int findMinInsertions(char str[], int l, int h)
{
    // Base Cases
    if (l > h) return INT_MAX;
    if (l == h) return 0;
    if (l == h - 1) return (str[l] == str[h])? 0 : 1;
 
    // Check if the first and last characters are same. On the basis of the
    // comparison result, decide which subrpoblem(s) to call
    return (str[l] == str[h])? findMinInsertions(str, l + 1, h - 1):
                               (min(findMinInsertions(str, l, h - 1), findMinInsertions(str, l + 1, h)) 
                                + 1);
}

/////////////////////////////////////////////////////////////////////////////////////////

// A DP function to find minimum number of insersions
int findMinInsertionsDP(char str[], int n)
{
    // Create a table of size n*n. table[i][j] will store
    // minumum number of insertions needed to convert str[i..j]
    // to a palindrome.
    int table[n][n], l, h, gap;
 
    // Initialize all table entries as 0
    memset(table, 0, sizeof(table));
 
    // Fill the table
    for (gap = 1; gap < n; ++gap)
        for (l = 0, h = gap; h < n; ++l, ++h)
            table[l][h] = (str[l] == str[h])? table[l+1][h-1] :
                          (min(table[l][h-1], table[l+1][h]) + 1);
 
    // Return minimum number of insertions for str[0..n-1]
    return table[0][n-1];
}

// another way using push dp
int minInsertion(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, INF));
    dp[0][n-1] = 0;
    int ans = INF;
    for (int L = 0; L < n; ++L) {
        for (int R = n-1; R >= 0; --R) {
            int curr = dp[L][R];
            // for odd length palindrome
            if (L == R) {
                ans = min(ans, curr);
                continue;
            }
            // for even length palindrome
            if (L + 1 == R and s[L] == s[R]) {
                ans = min(ans, curr);
                continue;
            }
            if (s[L] == s[R]) {
                dp[L+1][R-1] = min(dp[L+1][R-1], curr);
            }
            else {
                dp[L][R-1] = min(dp[L][R-1], curr);
                dp[L+1][R] = min(dp[L+1][R], curr);
            }
        }
    }

    return ans;
}
 
// Driver program to test above function.
int main()
{
    char str[] = "geeks";
    printf("%d", findMinInsertionsDP(str, strlen(str)));
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////
// best method //

int makePalindrome(string x){
	int n = x.size();
	string y = s.reverse();
	int L = LCS(x , y);

	return n - L ;
}


