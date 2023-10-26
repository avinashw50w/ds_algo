/*
Given the initial sequence of a coins, find the minimum number of coins that can be flipped to obtain a 
beautiful sequence. All head facing coins or tails facing coins sequence is also valid.
A beautiful sequence is such that there are consecutive heads followed by consecutive tails.
eg. HHHTTTT, HTTTT, HHHHT, HHHHH, TTTTT
*/

int solve(string coins) {
	int n = coins.size();
	vector<int> tleft(n, 0), hright(n, 0);

	for (int i = 1; i < n; ++i) {
		if (coins[i - 1] == 'T') tleft[i] = 1 + tleft[i-1];
	}

	for (int i = n-2; i>=0; --i) {
		if (coins[i+1] == 'H') hright[i] = 1 + hright[i + 1];
	}

	int res = n;
	for (int i = 0; i < n; ++i) {
		res = min(res, tleft[i] + hright[i]);
	}
}