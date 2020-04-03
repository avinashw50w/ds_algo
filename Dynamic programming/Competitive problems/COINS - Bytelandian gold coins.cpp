/*In Byteland they have a very strange monetary system.

Each Bytelandian gold coin has an integer number written on it. A coin n can be exchanged in a bank into three coins: n/2, n/3 and n/4. But these numbers are all rounded down (the banks have to make a profit).

You can also sell Bytelandian coins for American dollars. The exchange rate is 1:1. But you can not buy Bytelandian coins.

You have one gold coin. What is the maximum amount of American dollars you can get for it?

Input
The input will contain several test cases (not more than 10). Each testcase is a single line with a number n, 0 <= n <= 1 000 000 000. It is the number written on your coin.

Output
For each test case output a single line, containing the maximum amount of American dollars you can make.

Example
Input:
12
2

Output:
13
2*/
#include <iostream>
using namespace std;

const int MAXN = 1e6;
long long dp[MAXN];

long long solve(int n) {
	if(n < MAXN) {
		if(dp[n] != 0) return dp[n];
	}

	if(n < n/2 + n/3 + n/4)
		return solve(n/2) + solve(n/3) + solve(n/4);
	else {
		if(n < MAXN)
			dp[n] = n;
		return n;
	}
}

int main() {
	int t; 
	long long n;
	
	for(int i = 0; i < MAXN; ++i) dp[i] = solve(i);

	while(cin >> n) {
		
		cout << solve(n) << endl;
	}
}