/*Given a string, a partitioning of the string is a palindrome partitioning if every substring of the partition 
is a palindrome. For example, “aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”. 
Determine the fewest cuts needed for palindrome partitioning of a given string. For example, 
minimum 3 cuts are needed for “ababbbabbababa”. The three cuts are “a|babbbab|b|ababa”. 
If a string is palindrome, then minimum 0 cuts are needed. If a string of length n containing all different 
characters, then minimum n-1 cuts are needed.

Solution
This problem is a variation of Matrix Chain Multiplication problem. If the string is palindrome, 
then we simply return 0. Else, like the Matrix Chain Multiplication problem, we try making cuts at all 
possible places, recursively calculate the cost for each cut and return the minimum value.

Let the given string be str and minPalPartion() be the function that returns the fewest cuts needed for 
palindrome partitioning. following is the optimal substructure property.

// i is the starting index and j is the ending index. i must be passed as 0 and j as n-1
minPalPartion(str, i, j) = 0 if i == j. // When string is of length 1.
minPalPartion(str, i, j) = 0 if str[i..j] is palindrome.

// If none of the above conditions is true, then minPalPartion(str, i, j) can be 
// calculated recursively using the following formula.
minPalPartion(str, i, j) = Min { minPalPartion(str, i, k) + 1 +
                                 minPalPartion(str, k+1, j) } 
                           where k varies from i to j-1
*/

int minPalPartion(char *str)
{
    int n = strlen(str);
  
    /* C[i][j] = Minimum number of cuts needed for palindrome partitioning
                 of substring str[i..j]
       P[i][j] = true if substring str[i..j] is palindrome, else false
       Note that C[i][j] is 0 if P[i][j] is true */
    int C[n][n];
    bool P[n][n];
  
    int i, j, k, L; 
  
    // Every substring of length 1 is a palindrome
    for (i=0; i<n; i++)
    {
        P[i][i] = true;
        C[i][i] = 0;
    } 
    /* L is substring length. Build the solution in bottom up manner by
       considering all substrings of length starting from 2 to n.*/  
    for (L=2; L<=n; L++)
    {
        // For substring of length L, set different possible starting indexes
        for (i=0; i<=n-L; i++)
        {
            j = i+L-1; // Set ending index
  
            if (L == 2)
                P[i][j] = (str[i] == str[j]);
            else
                P[i][j] = (str[i] == str[j]) && P[i+1][j-1];
  
            // IF str[i..j] is palindrome, then C[i][j] is 0
            if (P[i][j] == true)
                C[i][j] = 0;
            else
            {
                // Make a cut at every possible localtion starting from i to j,
                // and get the minimum cost cut.
                C[i][j] = INT_MAX;
                for (k=i; k<j; k++)
                    C[i][j] = min (C[i][j], 1 + C[i][k] + C[k+1][j]);
            }
        }
    }
  
    // Return the min cut value for complete string. i.e., str[0..n-1]
    return C[0][n-1];
}
  
// Driver program to test above function
int main()
{
   char str[] = "ababbbabbababa";
   printf("Min cuts needed for Palindrome Partitioning is %d",
           minPalPartion(str));
   return 0;
}
// time complexity : O(n^3)
/////////////////////////////////////////////////////////////////////////////////////////////////
/*An optimization to above approach
In above approach, we r calculating minimum cut while finding all palindromic substring. 
If we find all palindromic substring 1st and then we calculate minimum cut, time complexity will reduce to O(n2).*/

int minPalPartion(char *str)
{
    int n = strlen(str);
  
    /* Create two arrays to build the solution in bottom up manner
       C[i] = Minimum number of cuts needed for palindrome partitioning
                 of substring str[0..i]
       P[i][j] = true if substring str[i..j] is palindrome, else false
       Note that C[i] is 0 if P[0][i] is true */
    int C[n];
    bool P[n][n];
  
    int i, j, k, L; // different looping variables
  
    // Every substring of length 1 is a palindrome
    for (i=0; i<n; i++)
    {
        P[i][i] = true;
    }
  
    for (L=2; L<=n; L++) {
        for (i=0; i<=n-L; i++) {
            j = i+L-1; // Set ending index
 
            if (L == 2)
                P[i][j] = (str[i] == str[j]);
            else
                P[i][j] = (str[i] == str[j]) && P[i+1][j-1];
        }
    }
 	// Method is similar to LIS
    for (i=0; i<n; i++)
    {	// if s[0..i] is a palindrome, then no of cuts = 0
        if (P[0][i] == true)
            C[i] = 0;
        else
        {	// start making cuts at every position from 1 to i
            C[i] = INT_MAX;
            for(j=0; j<i; j++)
            {
                // if str[0..j] is not a palindrome then C[j] will be INT_MAX. So 1+C[j] will always be greater 
                // than C[i] and the if condition will fai. We just need to check whether str[j+1..i] is a
                // palindrome or not
                if(P[j+1][i] == true && 1+C[j] < C[i])
                    C[i] = 1+C[j];
            }
        }
    }
  
    // Return the min cut value for complete string. i.e., str[0..n-1]
    return C[n-1];
}

///////////////////////////////////////////////////////////////////////////
// similar problem: find the min no of cuts needed to split a string such that each partition of the string is a word in the given dictionary


#include <bits/stdc++.h>
using namespace std;

set<string> dict;

int solve(string s) {
    int n = s.size();
    
    if (n == 0) return -1;
    
    int res = INT_MAX;
    for (int i = 0; i < n; ++i) {
        string left = s.substr(0, i+1);
        string right = s.substr(i+1, n-i);
        
        if (dict.count(left)) {
            int t = solve(right);
            
            if (t != INT_MAX and 1+ t < res) res = 1 + t;
        }
    }
    
    return res;
}

int main() {
    string s = "onpinsandneedle";
    
    dict.insert("on");
    dict.insert("pin");
    dict.insert("pins");
    dict.insert("and");
    dict.insert("sand");
    dict.insert("needles");
    int ans = solve(s);
    cout << (ans == INT_MAX ? -1: ans);
}
// time complexity: O(2^n)
///////////////////////////////////////////////////////////////////////////
// the above problem using DP
// time complexity: O(n^2)
#include <bits/stdc++.h>
using namespace std;

set<string> dict;
int dp[100]; // dp[i] store the min no of cuts needed to split the subtring s[0..i]

int solve(string s, int n) {
    fill(dp,dp+n,INT_MAX);
    for (int i = 0; i < n; ++i) {
        if (dict.count(s.substr(0, i+1))) dp[i] = 0;
        else {
            for (int j = 0; j < i; ++j) {
                if (dict.count(s.substr(j+1, i-j)) and 1+dp[j] < dp[i]) dp[i] = 1+dp[j];
            }
        }
    }
    
    return dp[n-1];
}

int main() {
    dict.insert("on");
    dict.insert("pin");
    dict.insert("pins");
    dict.insert("and");
    dict.insert("sand");
    dict.insert("needles");
    dict.insert("need");
    dict.insert("les");

    string s = "onpinsandneedles";

    int ans = solve(s, s.size());
    if (ans == INT_MAX) cout << -1;
    else cout << ans;
}