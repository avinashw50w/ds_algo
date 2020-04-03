/*Chef recently had been studying about Fibonacci numbers and wrote a code to print out the kth term of the 
Fibonacci series(1, 1, 2, 3, 5, 8, 13….). He was wondering whether he could write a program to generate the kth term for 
similar series. More specifically : T(n, k) is 1 if n <= k and T(n, k) = T(n-1, k) + T(n-2, k) + T(n-3, k) … + T(n-k, k) if n > k . 
Given n and k output T(n, k)%(1000000007) as the answer could be very large
Input
Two integers, N and K
Output
Output description.

One integer, the nth term of the series mod 1000000007
 

Constraints
1 ≤ N, K ≤ 2*105
Example
Input:
7 5

Output:
9*/

#include <iostream>
#include <string.h> // for memset
using namespace std;

typedef long long ll;
const int maxn = 1e5;
const int mod = 1e9 + 7;

ll dp[maxn + maxn];

ll solve(int n, int k)
{
	if(n <= k) return 1;

	if(dp[n] != -1) return dp[n];

	ll ret = 0;

	for(int i = 1; i <= k; ++i) {
		ret = (ret + solve(n-i, k)) % mod;
	}

	return dp[n] = ret;
}

int main()
{
	int N, K; cin >> N >> K;

	memset(dp, -1, sizeof(dp)); // initialize the dp array with -1

	cout << solve(N, K) << endl;
}