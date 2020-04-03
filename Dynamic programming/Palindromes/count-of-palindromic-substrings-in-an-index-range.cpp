/*Count of Palindromic substrings in an Index range
Given a string str of small alphabetic characters other than this we will be given many substrings 
of this string in form of index tuples. We need to find out the count of the palindromic substrings in given substring range.
Examples:

Input : String str = "xyaabax"
           Range1 = (3, 5)   
           Range2 = (2, 3) 
Output : 4
         3
For Range1,  substring is "aba"
Count of palindromic substring in "aba" is 
four : "a", "b", "aba", "a"
For Range2,  substring is "aa"
Count of palindromic substring in "aa" is 
3 : "a", "a", "aa"

Prerequisite : Count All Palindrome Sub-Strings in a String

We can solve this problem using dynamic programming. First we will make a 2D array isPalin, 
isPalin[i][j] will be 1 if string(i..j) is a palindrome otherwise it will be 0. 
After constructing isPalin we will construct another 2D array dp, dp[i][j] will tell 
the count of palindromic substring in string(i..j)
Now we can write the relation among isPalin and dp values as shown below,*/

// Utility method to construct the dp array 
void constructDP(int dp[M][M], string str) 
{ 
    int l = str.length(); 
  
    // declare 2D array isPalin, isPalin[i][j] will 
    // be 1 if str(i..j) is palindrome 
    int isPalin[l + 1][l + 1]; 
  
    for (int i = 0; i <= l; i++) { 
        for (int j = 0; j <= l; j++) { 
            isPalin[i][j] = dp[i][j] = 0; 
        } 
    } 
  
    for (int i = l - 1; i >= 0; i--) { 
  
        // initialize value for one character strings as 1 
        isPalin[i][i] = 1; 
        dp[i][i] = 1; 
  
        for (int j = i + 1; j < l; j++) { 
  
            /* isPalin[i][j] will be 1 if ith and 
               jth characters are equal and mid 
               substring str(i+1..j-1) is also a 
               palindrome             */
            isPalin[i][j] = (str[i] == str[j] && (i + 1 > j - 1 || isPalin[i + 1][j - 1])); 
  
            /* dp[i][j] will be addition of number 
               of palindromes from i to j-1 and i+1 
               to j subtracting palindromes from i+1 
               to j-1 (as counted twice) plus 1 if 
               str(i..j) is also a palindrome */
            dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1] + isPalin[i][j]; 
        } 
    } 
} 
  
// method returns count of palindromic substring in range (l, r) 
int countOfPalindromeInRange(int dp[M][M], int l, int r) 
{ 
    return dp[l][r]; 
} 
  
// Driver code to test above methods 
int main() 
{ 
    string str = "xyaabax"; 
  
    int dp[M][M]; 
    constructDP(dp, str); 
  
    int l = 3; 
    int r = 5; 
  
    cout << countOfPalindromeInRange(dp, l, r); 
    return 0; 
} 