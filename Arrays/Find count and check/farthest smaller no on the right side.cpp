/*Find the farthest smaller number in the right side

Given an array arr[] of size N. For every element in the array, the task is to find the index of the farthest element in the array to the right which is smaller than the current element. If no such number exists then print -1.

create a suffix_min[] array where suffix_min[i] stores the minimum element from the subarray arr[i … N – 1]. Now for any element arr[i], binary search can be used on the subarray suffix_min[i + 1 … N – 1] to find the farthest smallest element to the right of arr[i].*/

vector<int> solve(vector<int> a) {
	int n = a.size();
	vector<int> res(n);
	vector<int> suff(n);
	suff[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; --i) suff[i] = min(a[i], suff[i + 1]);

	for (int i = 0; i < n; ++i) {
		int l = i + 1, r = n - 1, mid, ans = -1;
		while (l <= r) {
			mid = l + (r - l) / 2;
			if (a[mid] < a[i]) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		res[i] = ans;
	}
	return res;
}