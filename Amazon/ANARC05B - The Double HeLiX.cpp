/*Two ﬁnite, strictly increasing, integer sequences are given. Any common integer between the
two sequences constitute an intersection point. Take for example the following two sequences
where intersection points are
printed in bold:

First= 3 5 7 9 20 25 30 40 55 56 57 60 62
Second= 1 4 7 11 14 25 44 47 55 57 100
You can ‘walk” over these two sequences in the following way:

You may start at the beginning of any of the two sequences. Now start moving forward.
At each intersection point, you have the choice of either continuing with the same sequence
you’re currently on, or switching to the other sequence.
The objective is ﬁnding a path that produces the maximum sum of data you walked over. In the
above example, the largest possible sum is 450, which is the result of
adding 3, 5, 7, 9, 20, 25, 44, 47, 55, 56, 57, 60, and 62*/

#define all(x) x.begin(), x.end()

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	map<int, int> mp;
	for (int &x : a) cin >> x, mp[x]++;
	for (int &x : b) cin >> x, mp[x]++;

	vector<int> prefix1(n + 1), prefix2(m + 1);
	for (int i = 0; i < n; ++i)
		prefix1[i + 1] = prefix1[i] + a[i];
	for (int i = 0; i < m; ++i)
		prefix2[i + 1] = prefix2[i] + b[i];

	int prevPos1 = -1, prevPos2 = -1;
	int ans = 0;

	for (auto p : mp) {
		if (p.second == 2) {
			int pos1 = lower_bound(all(a), p.first) - a.begin();
			int pos2 = lower_bound(all(b), p.first) - b.begin();

			int val1 = prefix1[pos1 + 1] - prefix1[prevPos1 + 1];
			int val2 = prefix2[pos2 + 1] - prefix2[prevPos2 + 1];

			prevPos1 = pos1;
			prevPos2 = pos2;

			ans += max(val1, val2);
		}
	}

	int val1 = prefix1[n] - prefix1[prevPos1 + 1];
	int val2 = prefix2[n] - prefix2[prevPos2 + 1];
	ans += max(val1, val2);

	return ans;
}