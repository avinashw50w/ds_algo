/*Count All Palindromic Subsequence in a given String
Find how many palindromic subsequence (need not necessarily be distinct) can be formed in a given string. Note that the empty string is not considered as a palindrome.
Examples:

Input : str = "abcd"
Output : 4
Explanation :- palindromic  subsequence are : "a" ,"b", "c" ,"d" 

Input : str = "aab"
Output : 4
Explanation :- palindromic subsequence are :"a", "a", "b", "aa"

Input : str = "aaaa"
Output : 15
Recommended: Please solve it on “PRACTICE” first, before moving on to the solution.


The above problem can be recursively defined.

Initial Values : i= 0, j= n-1;

CountPS(i,j)
// Every single character of a string is a palindrome 
// subsequence 
if i == j
   return 1 // palindrome of length 1

// If first and last characters are same, then we 
// consider it as palindrome subsequence and check
// for the rest subsequence (i+1, j), (i, j-1)
Else if (str[i] == str[j)]
   return   countPS(i+1, j) + countPS(i, j-1) + 1;

else
   // check for rest sub-sequence and  remove common
   // palindromic subsequences as they are counted
   // twice when we do countPS(i+1, j) + countPS(i,j-1)
   return countPS(i+1, j) + countPS(i, j-1) - countPS(i+1, j-1) 
If we draw recursion tree of above recursive solution, we can observe overlapping Subprolems. Since the problem has overlapping subproblems, we can solve it efficiently using Dynamic Programming. Below is Dynamic Programming based solution.*/

int countPS(string str) 
{ 
    int N = str.length(); 
  
    // create a 2D array to store the count of palindromic 
    // subsequence 
    int cps[N+1][N+1]; 
    memset(cps, 0 ,sizeof(cps)); 
  
    // palindromic subsequence of length 1 
    for (int i=0; i<N; i++) 
        cps[i][i] = 1; 
  
    // check subsequence of length L is palindrome or not 
    for (int L=2; L<=N; L++) 
    { 
        for (int i=0; i<N; i++) 
        { 
            int k = L+i-1; 
            if (str[i] == str[k]) 
                cps[i][k] = cps[i][k-1] + cps[i+1][k] + 1; 
            else
                cps[i][k] = cps[i][k-1] + cps[i+1][k] - cps[i+1][k-1]; 
        } 
    } 
  
    // return total palindromic subsequence 
    return cps[0][N-1]; 
} 
  
// Driver program 
int main() 
{ 
    string str = "abcb"; 
    cout << "Total palindromic subsequence are : "
         << countPS(str) << endl; 
    return 0; 
} 