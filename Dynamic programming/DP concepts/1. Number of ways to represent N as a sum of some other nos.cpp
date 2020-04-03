/*1. Given a number K, and some values - a1, a2, a3,..., an. Find the number of ways such that 
a1x1 + a2x2 + a3x3 + .... + anxn = K , where x1, x2, x3, ..., xn >= 0*/

int a[n];
int dp[K+1]; 

dp[0] = 1; // if all x1, x2, ..., xn are 0 then a sum of 0 is possilbe

// for each of the numbers a1, a2, ..., an
for(int i = 0; i < n; ++i)
	for(int j = a[i]; j <= K; ++j)
		dp[j] += dp[j-a[i]];


return dp[K]; // the required ans 

/*2. Second variation: 
Given a number K, and some values - a1, a2, a3,..., an. Find the number of ways such that 
a1x1 + a2x2 + a3x3 + .... + anxn = K , where x1, x2, x3, ..., xn >= 0 and x1+x2+x3+...+xn = P */

int a[n];
int dp[P+1][K+1];

dp[0][0] = 1;


for(int i = 0; i < n; ++i)
	for(int j = 1; j <= P; ++j)
		for(int k = a[i]; k <= K; ++k)
			dp[j][k] += dp[j-1][k-a[i]];

return dp[P][K]; // the required ans