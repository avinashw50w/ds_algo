/*Given an array of integers, you have to find the longest wiggle suquence.
A wiggle sequence is such that the a1 > a2 < a3 > a4 < ... or a1 < a2 > a3 < a4 > ...
eg. [1, 17, 5, 10, 13, 15, 10, 5, 16, 8]
ans = [1, 17, 5, 15, 5, 16, 8]

IDEA: let up[i] = longest alternate subsequnce such that a[i] > a[i-1]
down[i] = longest such subsequence such that a[i] < a[i-1]
So at each step, we can either take a[i] or not.
So if we take a[i] the up[i] = down[i-1] + 1, and if we don't then up[i] = up[i-1]
the up[i] = max(up[i-1], down[i-1] + 1) if a[i] > a[i-1] . eg a[i-2] > a[i-1] < a[i]
and down[i] = max(down[i-1], up[i-1] + 1) if a[i] < a[i-1]. eg a[i-2] < a[i-1] > a[i]
*/

int solve(vector<int> a) {
	int n = a.size();
	vector<int> up(n), down(n);
	up[0] = down[0] = 1;
	int ans = 1;

	for (int i = 1; i < n; ++i) {
		if (a[i] > a[i - 1])
			up[i] = max(up[i - 1], down[i - 1] + 1);
		else if (a[i] < a[i - 1])
			down[i] = max(down[i - 1], up[i - 1] + 1);
		ans = max(up[i], down[i]);
	}

	return ans;
}

//////////////////////////////////
// Space Optimized: since we are only considering the previous state
// we can just use 2 variables up and down

int solve(vector<int> a) {
	int n = a.size();
	int up = 1, down = 1;
	int ans = 1;
	for (int i = 1; i < n; ++i) {
		if (a[i] > a[i - 1])
			up = down + 1;
		else if (a[i] < a[i - 1])
			down = up + 1;

		ans = max(up, down);
	}

	return ans;
}