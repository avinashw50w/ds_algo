/*Maximum Product Cutting Problem.
BY SJ · JULY 11, 2015

Objec­tive: Given a rope of length n meters, write an algo­rithm to cut the rope in such a way 
that product of different lengths of rope is max­i­mum. At least one cut has to be made.

Note: Assume that the length of rope is more than 2 meters, since at least one cut has to be made.

This is yet another prob­lem where you will see the advan­tage of dynamic programming over recursion. 
I will show you how by storing and reusing the results of sub-problems will reduce the com­plex­ity of an algo­rithm significantly.

Example:

•	Rope length: 2 
•	Options: (1*1)
•	Maximum Product Cutting : 1*1 = 1

•	Rope length: 3 
•	Options: (1*1*1, 2*1)
•	Maximum Product Cutting : 2*1 = 2

•	Rope length: 4 
•	Options: (1*1*1*1, 2*1*1, 3*1, 2*2)
•	Maximum Product Cutting : 2*2 = 4
*/


int solve(int n) {
	if(n == 0 or n == 1) return 0;

	int res = 0;

	for(int i = 1; i < n; ++i) {
		res = max(res, max(i * (n-i), i * solve(n-i)));
	}
	return res;
}

/////////////////////////////////////////////////////////
// bottom up

int solve(int n) {
	
	int dp[n+1];
	dp[1] = 1;

	int tmp;

	for(int i = 2; i <= n; ++i) {
		tmp = INT_MIN;
		for(int j = 1; j < i; ++j)
			tmp = max(tmp, max(j * (i-j), j * dp[i-j]));

		dp[i] = tmp;
	}

	return dp[n];
}
