/*  gievn an array of K integers denoting the prices of K packets. The ith packet has weight of i kg.(i > 0)
You have to buy  packets having weight exactly K. If the price is -1, then the packet does not exist.
Input

The first line of input will contain the number of test cases, C.
Each test case will contain two lines.

The first line containing N and K, the number of friends he has 
and the amount of Apples in kilograms which he should buy.
The second line contains K space separated integers in which 
the ith integer specifies the price of a ‘i’kg apple packet. 
A value of -1 denotes that the corresponding packet is unavailable.

0 < N <= 100
0 < K <= 100
0 < price <= 1000
Output

The output for each test case should be a single line containing the minimum amount of money 
he has to spend for his friends. 
Print -1 if it is not possible for him to satisfy his friends*/

/*ESSENCE : Find the value of A[i1]+A[i2]+A[i3]+...+A[in] such that i1+i2+i3+...+in == K and 
			A[i1]+A[i2]+A[i3]+...+A[in] is minimum.  */

/*This is a problem of unbounded knapsack. 
We will maintain an array ans[ k+1 ] where the ans[i] stores the minimum money required to buy  i kg of apples. 
To find the optimal ans[ i ] , we need to decide whether to  select or reject an instance of weight 'j'.
If we reject all the weights then ans[ i ] = price[ i ], and if we select 'j'  then 
ans[ i ] = minimum[ ans[i - j] + price[ j ] ]  for j= 0,1....i-1.
*/

#include <iostream>
using namespace std;

int main() {
	int T, N, K;

	int P[101], dp[101];

	cin >> T;
	while(T--) {

		cin >> N >> K;

		for (int i = 1; i <= K; ++i) {
			cin >> P[i];
			dp[i] = P[i];
		}

		for (int i = 2; i <= K; ++i) {
			for (int j = 1; j < i; ++j) {
				if (P[i-j] == -1 || dp[j] == -1) continue;
				
				if (dp[i] == -1)
					dp[i] = dp[j] + P[i-j];
				else
					dp[i] = min(dp[i], dp[j] + P[i-j]);
			}
		}

		(K == 0) ? cout << -1 : cout << dp[K];
		cout << endl;
	}
}