/*Given two integers n and k, find how many different arrays consist of numbers from 1 to n 
such that there are exactly k inverse pairs.
We define an inverse pair as following: For ith and jth element in the array, if i < j and a[i] > a[j] 
then it's an inverse pair; Otherwise, it's not.
Since the answer may very large, the answer should be modulo 109 + 7.
Example 1:
Input: n = 3, k = 0
Output: 1
Explanation: 
Only the array [1,2,3] which consists of numbers from 1 to 3 has exactly 0 inverse pair.
Example 2:
Input: n = 3, k = 1
Output: 2
Explanation: 
The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.
Note:
The integer n is in the range [1, 1000] and k is in the range [0, 1000].

For example, if we have some permutation of 1...4
5 x x x x creates 4 new inverse pairs
x 5 x x x creates 3 new inverse pairs
...
x x x x 5 creates 0 new inverse pairs
O(N * K ^ 2) SOLUTION

We can use this formula to solve this problem
dp[i][j] //represent the number of permutations of (1...n) with k inverse pairs.
dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j-2] + ..... +dp[i-1][j - i + 1]
So, We write a O(k*n^2) Solution through above formula like this

(n+1,k) means the sum of arrays that consist of n+1 number with k inverse pairs.
for arrays that match (n,k),we put the (N+1)th number at the end ,so the new array match (n+1,k).
for arrays that match (n,k-1),we put the (N+1)th number before the last number, the sum of inverse pairs increase 1,
so the new array match (n+1,k).
...
the max increase is n (put the (N+1)th number at the begin)
Thus (n+1,k) equals (n,k)+(n,k-1)+(n,k-2)+.....+（n,k-n）
below is my code: */

public class Solution {
	int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k+1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; ++i){
            for(int j = 0; j < i; ++j){ // In number i, we can create 0 ~ i-1 inverse pairs 
                for(int m = 0; m <= k; ++m){ //dp[i][m] +=  dp[i-1][m-j]
                    if(m - j >= 0 && m - j <= k){
                        dp[i][m] = (dp[i][m] + dp[i-1][m-j]) % mod; 
                    }
                }
            }
        }
        return dp[n][k];
    }
    const int mod = pow(10, 9) + 7;

}

////////////////////////////////////////////////////////////////////

public int kInversePairs(int n, int k) {
    int[][] dp = new int[n + 1][k + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j == 0)
                dp[i][j] = 1;
            else {
                for (int p = 0; p <= Math.min(j, i - 1); p++)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - p]) % 1000000007;
            }
        }
    }
    return dp[n][k];
}




