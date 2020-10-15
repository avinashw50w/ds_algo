/*Find the farthest smaller number in the right side

Given an array arr[] of size N. For every element in the array, the task is to find the index of the farthest element in the array to the right which is smaller than the current element. If no such number exists then print -1.

create a suffix_min[] array where suffix_min[i] stores the minimum element from the subarray arr[i … N – 1]. Now for any element arr[i], binary search can be used on the subarray suffix_min[i + 1 … N – 1] to find the farthest smallest element to the right of arr[i].*/

int find(vector<int> a, int l, int r, int x) {
	int m, ans = -1;
	while (l <= r) {
		m = l + (r - l) / 2;
		if (a[m] < x) ans = m, l = m + 1;
		else r = m - 1;
	}

	return ans;
}

vector<int> solve(vector<int> a) {
	int n = a.size();
	vector<int> res(n);

	for (int i = 0; i < n; ++i) {
		res[i] = find(a, i + 1, n - 1, a[i]);
	}

	return res;
}