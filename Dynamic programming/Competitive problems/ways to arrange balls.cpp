/*Ways to arrange Balls such that adjacent balls are of different types
There are ‘p’ balls of type P, ‘q’ balls of type Q and ‘r’ balls of type R. Using the balls we want to create a straight line such that no two balls of same type are adjacent.
Naive Solution:
The naive solution to this problem is a recursive solution. We recursively call for three cases
1) Last ball to be placed is of type P
2) Last ball to be placed is of type Q
3) Last ball to be placed is of type R

Qelow is C++ implementation of above idea.*/

// C++ program to count number of ways to arrange three
// types of balls such that no two balls of same color
// are adjacent to each other
#include <bits/stdc++.h>
using namespace std;
 
// Returns count of arrangements where last placed ball is
// 'last'.  'last' is 0 for 'p', 1 for 'q' and 2 for 'r'
int countWays(int p, int q, int r, int last)
{
    // if number of balls of any color becomes less
    // than 0 the number of ways arrangements is 0.
    if (p<0 || q<0 || r<0)
        return 0;
 
    // If last ball required is of type P and the number
    // of balls of P type is 1 while number of balls of
    // other color is 0 the number of ways is 1.
    if (p==1 && q==0 && r==0 && last==0)
        return 1;
 
    // Same case as above for 'q' and 'r'
    if (p==0 && q==1 && r==0 && last==1)
        return 1;
    if (p==0 && q==0 && r==1 && last==2)
        return 1;
 
    // if last ball required is P and the number of ways is
    // the sum of number of ways to form sequence with 'p-1' P
    // balls, q Q Balls and r R balls ending with Q and R.
    if (last==0)
        return countWays(p-1,q,r,1) + countWays(p-1,q,r,2);
 
    // Same as above case for 'q' and 'r'
    if (last==1)
        return countWays(p,q-1,r,0) + countWays(p,q-1,r,2);
    if (last==2)
        return countWays(p,q,r-1,0) + countWays(p,q,r-1,1);
}
 
// Returns count of required arrangements
int countUtil(int p, int q, int r)
{
   // Three cases arise:
   return countWays(p, q, r, 0) +  // Last required balls is type P
          countWays(p, q, r, 1) +  // Last required balls is type Q
          countWays(p, q, r, 2); // Last required balls is type R
}
 
// Driver code to test above
int main()
{
    int p = 1, q = 1, r = 1;
    printf("%d", countUtil(p, q, r));
    return 0;
}
/*
Output:

6
Time Complexity of this solution is exponential.

We can observe that there are many subproblems being solved again and again so the problem can be solved using Dynamic Programming (DP). We can easily make memoization solution to this problem.*/

// C++ program to count number of ways to arrange three
// types of balls such that no two balls of same color
// are adjacent to each other
#include <bits/stdc++.h>
using namespace std;
#define MAX 100
 
// table to store to store results of subproblems
int dp[MAX][MAX][MAX][3];
 
// Returns count of arrangements where last placed ball is
// 'last'.  'last' is 0 for 'p', 1 for 'q' and 2 for 'r'
int countWays(int p, int q, int r, int last)
{
    // if number of balls of any color becomes less
    // than 0 the number of ways arrangements is 0.
    if (p<0 || q<0 || r<0)
        return 0;
 
    // If last ball required is of type P and the number
    // of balls of P type is 1 while number of balls of
    // other color is 0 the number of ways is 1.
    if (p==1 && q==0 && r==0 && last==0)
        return 1;
 
    // Same case as above for 'q' and 'r'
    if (p==0 && q==1 && r==0 && last==1)
        return 1;
    if (p==0 && q==0 && r==1 && last==2)
        return 1;

    int &res = dp[p][q][r][last];
 
    // If this subproblem is already evaluated
    if (res != -1)
        return res;
 
    // if last ball required is P and the number of ways is
    // the sum of number of ways to form sequence with 'p-1' P
    // balls, q Q Balls and r R balls ending with Q and R.
    if (last==0)
       res = countWays(p-1,q,r,1) + countWays(p-1,q,r,2);
 
    // Same as above case for 'q' and 'r'
    else if (last==1)
       res = countWays(p,q-1,r,0) + countWays(p,q-1,r,2);
    else //(last==2)
       res =  countWays(p,q,r-1,0) + countWays(p,q,r-1,1);
 
    return res;
}
 
// Returns count of required arrangements
int countUtil(int p, int q, int r)
{
   // Initialize 'dp' array
   memset(dp, -1, sizeof(dp));
 
   // Three cases arise:
   return countWays(p, q, r, 0) +  // Last required balls is type P
          countWays(p, q, r, 1) +  // Last required balls is type Q
          countWays(p, q, r, 2); // Last required balls is type R
}
 
// Driver code to test above
int main()
{
    int p = 1, q = 1, r = 1;
    printf("%d", countUtil(p, q, r));
    return 0;
}

/*
Output:

6
Time complexity : O(p*q*r)
Auxiliary Space : O(p*q*r*3)

*/