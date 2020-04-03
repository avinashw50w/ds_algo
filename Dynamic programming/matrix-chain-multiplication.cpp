/*Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications, 
but merely to decide in which order to perform the multiplications.

We have many options to multiply a chain of matrices because matrix multiplication is associative. In other words, no matter how we parenthesize the product, 
the result will be the same. For example, if we had four matrices A, B, C, and D, we would have:

    (ABC)D = (AB)(CD) = A(BCD) = ....
However, the order in which we parenthesize the product affects the number of simple arithmetic operations needed to compute the product, or the efficiency. 
For example, suppose A is a 10 × 30 matrix, B is a 30 × 5 matrix, and C is a 5 × 60 matrix. Then,

    (AB)C = (10×30×5) + (10×5×60) = 1500 + 3000 = 4500 operations
    A(BC) = (30×5×60) + (10×30×60) = 9000 + 18000 = 27000 operations.
Clearly the first parenthesization requires less number of operations.

Given an array p[] which represents the chain of matrices such that the ith matrix Ai is of dimension p[i-1] x p[i]. We need to write a function 
MatrixChainOrder() that should return the minimum number of multiplications needed to multiply the chain.

  Input: p[] = {40, 20, 30, 10, 30}   
  Output: 26000  
  There are 4 matrices of dimensions 40x20, 20x30, 30x10 and 10x30.
  Let the input 4 matrices be A, B, C and D.  The minimum number of 
  multiplications are obtained by putting parenthesis in following way
  (A(BC))D --> 20*30*10 + 40*20*10 + 40*10*30*/


int fun(int p[], int i, int j) {
	if(i == j) return 0;

	int cnt = 0, ans = (int)1e9;

	for(int k = i; k < j; ++k) {
		cnt = fun(p, i, k) + fun(p, k+1,j) + p[i-1]*p[k]*p[j];
		ans = min(ans, cnt);
	}
	return ans;
}

///////////////////////////////////////////////////////////////////

int fun(int p[], int n) {
	int cnt = 0;

	int dp[n][n] = {};

	for(int i=0;i<n;++i) dp[i][i] = 0;

	// L is the length of the chain //
	for(int L = 2; L < n; ++L) {
		for(int i = 1; i < n-L+1; ++i) {
			int j = i+L-1;
			dp[i][j] = (int)1e9;
			for(int k = i; k < j; ++k) {
				cnt = dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j];

				dp[i][j] = min(cnt, dp[i][j]);
			}
		}
	}
	return dp[1][n-1];
}