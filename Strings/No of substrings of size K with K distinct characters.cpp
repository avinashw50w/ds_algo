/*Count the number of substrings of size K having exactly K distinct characters.*/

int solve(string s, int K) {
	int cnt = 0;
	unordered_map<char, int> mp;

	for (int i = 0; i < K; ++i)
		mp[s[i]]++;

	cnt += mp.size() == K;

	for (int i = K; i < n; ++i) {
		mp[s[i]]++;
		mp[s[i - K]]--;

		if (mp[s[i - K]] == 0)
			mp.erase(s[i - K]);

		cnt += mp.size() == K;
	}

	return cnt;
}