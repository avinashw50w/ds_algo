/*given an array with N elements, count the no of pairs whose sum is divisible by K.
idea: store the value of a[i] % K in an array
case 1: both the nos are divisible by K
	- in this case, the no of pairs = no of ways to choose any two such elements
	= nC2 = freq[0] * (freq[0] - 1) / 2

case 2: one number's remainder is i and the other one's remainder is K - i
	- in this case the answer will be freq[i] * freq[K - i];

case 3: if K is even and the remainder of both the nos is K/2
	- the no of pairs = number of ways to choose any two such numbers
	= freq[K/2] * (freq[K/2]) / 2

the final answer is the sum of all the three cases
*/

int solve(vector<int> a, int K) {
	int n = a.size();
	unordered_map<int, int> mp;
	for (int i = 0; i < n; ++i) mp[a[i] % K]++;

	// case 0
	int ans = (mp[0] * (mp[0] - 1)) / 2;
	// case i and K - i
	for (int i = 1; i <= K / 2 and i != K - i; ++i)
		ans += mp[i] * mp[K - i];
	// case K/2 iff K is even
	if (K & 1 ^ 1) ans += (mp[K / 2] * (mp[K / 2] - 1)) / 2;

	return ans;
}

/// second easy way
int solve(vector<int> a, int K) {
	int n = a.size();
	unordered_map<int, int> mp;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int rem = a[i] % K;
		ans += mp[(K - rem) % K];
		mp[rem]++;
	}

	return ans;
}