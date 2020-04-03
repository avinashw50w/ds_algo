/*There are N persons sitting on a round table. Find the no of handshakes possible such that
there is no overlapping of handshakes between 2 people. N is even.*/

/*For eg. there are 6 persons 
	1 2 3 4 5 6 

	here if 2 shakes hand with 4, then 3 cant shake hand with any person because of overlapping

*/

/*If person 1 shakes hand with person i, then divide the table into two sets: [2..i-1] and [i+1...n] */

int dp[N+1];

int solve(int N) {
	// if there are 0 people, then 1 way ie no handshakes
	if (N == 0) return 1; 
	// if only 1 person, then 0, coz need atleast 2 people for handshakes
	if (N == 1) return 0;

	if (dp[N] != -1) return dp[N];
	// if person 1 shake hands with person i
	for (int i = 2; i <= N; ++i)
		dp[i] = solve(i-2) * solve(n-i);

	return dp[i];
}

int handshakes(int N) {
	memset(dp, -1, sizeof(dp));

	return solve(N);
}

////////////////////////////////////////////////
// ans is catalan[N/2]


void catalan(vector<int> &C) {
	C[0] = C[1] = 1;

	for (int i = 2; i <= N; ++i) {
		for (int j = 0; j < i; ++j)
			C[i] += C[j] * C[i-j-1];
	}
}

int solve(int N) {
	vector<int> C(N, 0);

	catalan(C);

	return C[N>>1];
}

