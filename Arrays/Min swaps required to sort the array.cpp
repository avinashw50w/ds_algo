/*Minimum number of swaps required to sort an array
Given an array of n distinct elements, find the minimum number of swaps required to sort the array.

Examples:

Input : {4, 3, 2, 1}
Output : 2
Explanation : Swap index 0 with 3 and 1 with 2 to
              form the sorted array {1, 2, 3, 4}.
IDEA: find the cycle lengths, a cycle is formed when you link a[i] to a[a[i]] and keeps repeating it.
NOTE: Such a cycle with n elements can be sorted by swapping n-1 element pairs
SO ans = 
*/

// when numbers are in the range [1...n]
int solve(vector<int> a) {
	int ans = 0, n = a.size();
	vector<int> vis(n + 1);
	for (int i = 0; i < n; ++i) {
		int j = i, cnt = 0;
		while (!vis[j]) {
			vis[j] = 1;
			j = a[j] - 1;
			cnt++;
		}

		ans += max(0, cnt - 1);
	}

	return ans;
}
// when the numbers are any distinct n integers, then we will have to use their index

int solve(vector<int> a) {
	int n = a.size();
	vector<array<int, 2>> v;
	for (int i = 0; i < n; ++i) v[i] = {a[i], i};
	sort(v.begin(), v.end());
	vector<int> vis(n);

	for (int i = 0; i < n; ++i) {
		int j = i, cnt = 0;
		while (!vis[j]) {
			vis[j] = 1;
			cnt++;
			j = a[j][1];
		}

		ans += max(0, cnt - 1);
	}

	return ans;
}