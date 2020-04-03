/* If A to Z are coded as 1 to 26, then Count the number of possible decoding for a given number like 26 can be 
   Z or BF. */

/*Let dp[i] stores the count of possible decodings if number of digits in the given number is i. */

#include <iostream>
#include <cstring>
using namespace std;

typedef long long int ll;

ll dp[5555];

ll solve(string code) {

	int N = code.length();
	
	memset(dp, 0, sizeof dp);	
	dp[0] = dp[1] = 1;

	for (int i = 2; i <= N; ++i) {
		if (code[i-1] >= '1')
			dp[i] += dp[i-1];

		if (code[i-2] == '1' || (code[i-2] == '2' && code[i-1] <= '6'))
			dp[i] += dp[i-2];
	}

	return dp[N];
}

int main() {
	string N;

	while(cin >> N) {
		if (N[0] == '0') break;

		cout << solve(N) << endl;
	}
}