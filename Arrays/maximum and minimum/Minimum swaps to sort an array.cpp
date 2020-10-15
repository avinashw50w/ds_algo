/*Minimum number of swaps required to sort an array
Given an array of n distinct elements, find the minimum number of swaps required to sort the array.
Input : {4, 3, 2, 1}
Output : 2
Explanation : Swap index 0 with 3 and 1 with 2 to
              form the sorted array {1, 2, 3, 4}.

Input : {1, 5, 4, 3, 2}
Output : 2

IDEA: find the no of cycles formed
ans = ∑(cycle length - 1)
*/

int minimumSwaps(vector<int> a) {

	int n = a.size();
	vector<int> vis(n, 0);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int cnt = 0, j = i;
		while (!vis[j]) {
			vis[j] = 1;
			cnt++;
			j = a[j] - 1;
		}

		if (cnt > 1) ans += cnt - 1;
	}
	return ans;
}

////////////////////////////////////////
// case when a[i] are not in the range of 1 to n or are greater than 10^5
// take another vector or pairs where first and second of a pair will be the number and its index respectively
// then sort the vector according to the value

int solve(vector<int> a) {

	vector<pair<int, int>> v;
	for (int i = 0; i < a.size(); ++i) {
		v.push_back({ a[i], i });
	}

	sort(v.begin(), v.end());
	vector<int> vis(a.size(), 0);
	int ans = 0;

	for (int i = 0; i < a.size(); ++i) {
		int cnt = 0, j = i;
		while (!vis[j]) {
			vis[j] = 1;
			cnt++;
			j = v[j].second;
		}
		ans += cnt > 1 ? cnt - 1 : 0;
	}

	return ans;
}
