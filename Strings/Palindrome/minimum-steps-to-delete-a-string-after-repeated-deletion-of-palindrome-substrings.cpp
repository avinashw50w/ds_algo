/*Minimum steps to delete a string after repeated deletion of palindrome substrings
Given a string containing characters as integers only. We need to delete all character 
of this string in a minimum number of steps where in one step we can delete the substring 
which is a palindrome. After deleting a substring remaining parts are concatenated.
Examples:

Input : s = “2553432”
Output : 2
We can delete all character of above string in
2 steps, first deleting the substring s[3, 5] “343”  
and then remaining string completely  s[0, 3] “2552”


We can solve this problem using Dynamic programming. Let dp[i][j] denotes the number of steps it 
takes to delete the substring s[i, j]. Each character will be deleted alone or as part of some 
substring so in the first case we will delete the character itself and call subproblem (i+1, j). 
In the second case we will iterate over all occurrence of the current character in right side, 
if K is the index of one such occurrence then the problem will reduce to two subproblems (i+1, K – 1) 
and (K+1, j). We can reach to this subproblem (i+1, K-1) because we can just delete the same
 character and call for mid substring. We need to take care of a case when first two characters 
 are same in that case we can directly reduce to the subproblem (i+2, j)

So after above discussion of relation among subproblems, we can write dp relation as follows,

dp[i][j] = min(1 + dp[i+1][j], // delete the ith character
          dp[i+1][K-1] + dp[K+1][j],  where s[i] == s[K]
          1 + dp[i+2][j]  // s[i] == s[i+1] then delete both of them
          ) 

*/