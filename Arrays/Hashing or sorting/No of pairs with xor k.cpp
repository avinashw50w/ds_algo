/*given an array of intergers, find the no of pairs whose xor is K.
IDEA: a xor b = c, implies a xor c = b, also implies b xor c = a
*/

int solve(vector<int> a, int K) {
	unordered_map<int, int> mp;
	int n = a.size();
	int ans = 0;

	for (int i = 0; i < n; ++i) {
		int x = a  ^ K;
		if (mp.count(x)) ans += mp[x];
		mp[x]++;
	}

	return ans;
}