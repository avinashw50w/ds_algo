/* Count the number of ways to represent N as sum of power of 2. */

/*Suppose g(n) is the number of ways to write m as a sum of powers of 2. We use f(n,k) to represent the number of ways to 
write n as a sum of powers of 2 with all the numbers' power is less than or equal to k. Then we can reduce to the equation:

if n==0 f(n,k)=1;    
if k<0 f(n,k)=0;    
if k==0 f(n,k)=1;    
if n>=power(2,k) f(n,k)=f(n-power(2,k),k)+f(n,k-1);//we can use power(2,k) as one of the numbers or not.    
else f(n,k)=f(n,k-1);  */


int solve(int n, int k) {

	if (n == 0 || k == 0) return 1;
	if (k < 0) return 0;

	if (n >= power(2, k))
		return solve(n - power(2, k), k) + solve(n, k-1);

	else return solve(n, k-1);
}

int main() {

	int N, K;

	cin >> N;

	K = log(N);

	cout << solve(N, K)
}

//////////////////////////////////////////////////
// dp solution
// T: O((logN + logK)^K)
int solve(int n, int k) {
	if (n == 0 || k == 0) return 1;
	if (k < 0) return 0;

	if (dp[n][k] != -1) return dp[n][k];

	if (n >= power(2, k))
		return dp[n][k] = solve(n - power(2, k), k) + solve(n, k-1);

	else return dp[n][k] = solve(n, k-1);
}

////////////////////////////////////////////////////////////////
// T: O(NlogN)
int solve(int n) {
	vector<int> dp(n+1, 0);
	// 1 way to represent 0 as a sum of power of 2
	dp[0] = 1;

	// iterate through all powers of 2 upto n
	for (int i = 1; i <= n; ++i) {
		// iterate through all the #s from 2^i upto n
		for (int j = i; j <= n; ++j) {
			dp[j] += dp[i-j];
		}
	}

	return dp[n];
}