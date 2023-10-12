/* https://cybergeeksquad.co/2023/03/split-string-into-unique-primes-solution-amazon-oa.html
Given a string made up of integers 0 to 9, count the number of ways to split the string into prime numbers 
in the range of 2 to 1000 inclusive, using up all the characters in the string.
*/

class Solution {
	static int MOD = 1e9 + 7;

	vector<int> sieve(int n) {
		vector<int> primes(n+1, 1);
		isPrime[0] = isPrime[1] = 0;
		for (int i = 2; i * i <= n; ++i){
			if (isPrime[i] == 0) continue;
			for (int j = i * i; j <= n; j += i) isPrime[i] = 0;
		}
		
		return isPrime;
	}

	int solve(string s) {
		int n = s.length();
		vector<long> dp(n + 1, 0);
		dp[0] = 1;

		for (int i = 1; i <= n; ++i) {
			if (s[i-1] != '0' and isPrime[s[i-1] - '0']) 
				dp[i] = dp[i-1];
			if (i-2 >= 0 and s[i-2] != '0' and isPrimes[stoi(s.substr(i-2, 2))])
				dp[i] = (dp[i] + dp[i-2]) % mod;
			if (i-3 >= 0 and s[i-3] != '0' and isPrimes[stoi(s.substr(i-3, 3))])
				dp[i] = (dp[i] + dp[i-3]) % mod;
		}

		return dp[n];
	}
}